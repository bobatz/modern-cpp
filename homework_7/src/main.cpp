#include "kmeans.h"
#include "convert_dataset.hpp"
#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

int main() {
  std::cout << "Hello world!\n";

  // Save SIFT descriptors to file
  std::string directory = "/home/amarbold/courses/modern-cpp/homework_7/tests/data/freiburg/images";
  fs::path directory_path = fs::path(directory) / ".." / "bin";
  if (!fs::exists(directory_path)) {
    ipb::serialization::sifts::ConvertDataset(directory);
    std::cout << "Saved descriptors to file.\n";
  }

  // Load SIFT descriptors from file.
  std::vector<cv::Mat> descriptors = ipb::serialization::sifts::LoadDataset(directory_path.string());
  std::cout << "Loaded " << descriptors.size() << " descriptor matrices.\n";

  // k-means cluster
  cv::Mat means = ipb::kMeans(descriptors, 3, 100);
  std::cout << "Rows in means: " << means.rows << std::endl;

  return 0;
}
