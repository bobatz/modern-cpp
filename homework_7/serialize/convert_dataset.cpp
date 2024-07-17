#include "serialize.hpp"
#include <filesystem>
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>

namespace ipb::serialization::sifts {
void ConvertDataset(const std::filesystem::path& img_path) {
  std::filesystem::path bin_path = img_path / ".." / "bin";
  if (!std::filesystem::exists(bin_path)) {
    std::filesystem::create_directories(bin_path);
  }
  if (!std::filesystem::exists(img_path)) {
    std::cerr << "Image directory does not exist.\n";
    return;
  }
  auto detector = cv::SiftFeatureDetector::create();
  auto extractor = cv::SiftDescriptorExtractor::create();
  for (auto& entry : std::filesystem::directory_iterator(img_path)) {
    std::filesystem::path p = entry.path();
    if (p.extension() != ".png") {
      continue;
    }
    cv::Mat m = cv::imread(p.string());
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(m, keypoints);
    cv::Mat descriptors;
    extractor->compute(m, keypoints, descriptors);
    std::filesystem::path file_path = bin_path / (p.stem().string() + ".bin");
    ipb::serialization::Serialize(descriptors, file_path.string());
  }
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path& bin_path) {
  std::vector<cv::Mat> descriptors;
  if (!std::filesystem::exists(bin_path)) {
    std::cerr << "Binary directory does not exist.\n";
    return descriptors;
  }
  for (auto& entry : std::filesystem::directory_iterator(bin_path)) {
    std::filesystem::path p = entry.path();
    if (p.extension() != ".bin") {
      continue;
    }
    cv::Mat m = ipb::serialization::Deserialize(p.string());
    descriptors.emplace_back(m);
  }
  return descriptors;
}

}  // namespace ipb::serialization::sifts
