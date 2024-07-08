#include "serialize.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>

namespace ipb::serialization {

void Serialize(const cv::Mat &m, const std::string &filename) {
  int rows = m.rows;
  int cols = m.cols;
  int channels = m.channels();

  if (m.depth() != CV_8U) {
    std::cerr << "Mat type is not CV_8U.\n";
    return;
  }
  if (!m.isContinuous()) {
    std::cerr << "Mat is not continuous.\n";
    return;
  }
  std::vector<uchar> data = m.data;
  std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);
  file.write(reinterpret_cast<char *>(&rows), sizeof(rows));
  file.write(reinterpret_cast<char *>(&cols), sizeof(cols));
  file.write(reinterpret_cast<char *>(&channels), sizeof(channels));
  file.write(reinterpret_cast<char *>(&data.front()),
             data.size() * sizeof(data.front()));
}

cv::Mat Deserialize(const std::string &filename) {
  std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);
  file.open();
  if (file.fail()) {
    std::cerr << "File failed to open.\n";
  }
  int rows = 0;
  int cols = 0;
  int channels = 0;
  file.read(reinterpret_cast<char *>(&rows), sizeof(rows));
  file.read(reinterpret_cast<char *>(&cols), sizeof(cols));
  file.read(reinterpret_cast<char *>(&channels), sizeof(channels));
  cv::Mat m(rows, cols, CV_8U, cv::Scalar(0, 0, 0));
  file.read(reinterpret_cast<char *>(&m.data.front()),
            rows * cols * channels * sizeof(&m.data.front()));
  return m;
}

} // namespace ipb::serialization
