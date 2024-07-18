#include "kmeans.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <opencv2/core.hpp>

namespace ipb {
cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter) {
  cv::Mat points;
  cv::vconcat(descriptors, points);

  // Choose the first k points as centroids.
  std::vector<cv::Mat> centroids;
  for (int i = 0; i < k; i++) {
    centroids.emplace_back(points.row(i));
  }
  std::cout << "Centroids: " << centroids.size() << std::endl;

  for (int iter = 0; iter < max_iter; iter++) {
    std::cout << "---Iteration: " << iter << "---\n";

    // Start with empty clusters.
    std::map<int, std::vector<cv::Mat>> clusters;
    for (int i = 0; i < centroids.size(); i++) {
      clusters[i] = std::vector<cv::Mat>();
    }

    // Cluster points to the nearest centroid.
    for (int i = 0; i < points.rows; i++) {
      cv::Mat point = points.row(i);
      int nearest_index = GetNearestCentroid(point, centroids);
      clusters[nearest_index].emplace_back(point);
    }

    // Calculate new centroids.
    std::vector<cv::Mat> new_centroids;
    for (int i = 0; i < clusters.size(); i++) {
      std::cout << "Cluster " << i << ": " << clusters[i].size() << std::endl;
      cv::Mat centroid = GetCentroid(clusters[i]);
      new_centroids.emplace_back(centroid);
    }

    // If old and new centroids match, converge.
    bool converged = true;
    for (int i = 0; i < centroids.size(); i++) {
      if (NotEqual(centroids[i], new_centroids[i])) {
        converged = false;
        centroids = new_centroids;
        break;
      }
    }
    if (converged) {
      break;
    }
  }

  cv::Mat result;
  cv::vconcat(centroids, result);
  return result;
}

double GetDistance(cv::Mat a, cv::Mat b) { return cv::norm(a, b); }

int GetNearestCentroid(cv::Mat point, std::vector<cv::Mat> centroids) {
  std::vector<double> distances;
  for (int i = 0; i < centroids.size(); i++) {
    distances.emplace_back(GetDistance(point, centroids[i]));
  }
  std::vector<double>::iterator it =
      std::min_element(distances.begin(), distances.end());
  return std::distance(distances.begin(), it);
}

cv::Mat GetCentroid(std::vector<cv::Mat> points) {
  cv::Mat m;
  cv::vconcat(points, m);
  cv::Mat centroid;
  cv::reduce(m, centroid, 0, cv::REDUCE_AVG);
  return centroid;
}

bool NotEqual(cv::Mat a, cv::Mat b) { return cv::countNonZero(a != b); }
} // namespace ipb
