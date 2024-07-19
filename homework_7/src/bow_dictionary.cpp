#include "bow_dictionary.h"
#include "kmeans.h"
#include "opencv2/core/mat.hpp"
#include <vector>

namespace ipb {
int BowDictionary::max_iterations() const {
  return max_iterations_;
}

int BowDictionary::size() const {
  return size_;
}

std::vector<cv::Mat> BowDictionary::descriptors() const {
  return descriptors_;
}

cv::Mat BowDictionary::vocabulary() const {
  return dictionary_;
}

int BowDictionary::total_features() const {
  int features = 0;
  for (auto& d : descriptors_) {
    features += d.rows;
  }
  return features;
}

bool BowDictionary::empty() const {
  return size_ == 0;
}

void BowDictionary::set_max_iterations(int max_iterations) {
  max_iterations_ = max_iterations;
  calculate();
}

void BowDictionary::set_size(int size) {
  size_ = size;
  calculate();
}

void BowDictionary::set_descriptors(std::vector<cv::Mat> descriptors) {
  descriptors_ = descriptors;
  calculate();
}

void BowDictionary::set_params(int max_iterations, int size, std::vector<cv::Mat> descriptors) {
  max_iterations_ = max_iterations;
  size_ = size;
  descriptors_ = descriptors;
  calculate();
}

void BowDictionary::calculate() {
  dictionary_ = kMeans(descriptors_, size_, max_iterations_);
}
} // namespace ipb
