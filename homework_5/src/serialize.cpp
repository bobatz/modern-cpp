#include "serialize.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <vector>

namespace ipb::serialization {

void Serialize(const cv::Mat &m, const std::string &filename) {
  int rows = m.rows;
  int cols = m.cols;
  int channels = m.channels();
  int type = m.type();
  if (!m.isContinuous()) {
    std::cerr << "Mat is not continuous.\n";
    return;
  }
  std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);
  file.write(reinterpret_cast<char *>(&rows), sizeof(rows));
  file.write(reinterpret_cast<char *>(&cols), sizeof(cols));
  file.write(reinterpret_cast<char *>(&channels), sizeof(channels));
  file.write(reinterpret_cast<char *>(&type), sizeof(type));
  file.write(reinterpret_cast<char *>(m.data), GetDataSize(m));
}

cv::Mat Deserialize(const std::string &filename) {
  std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);
  if (file.fail()) {
    std::cerr << "File failed to open.\n";
  }
  int rows = 0;
  int cols = 0;
  int channels = 0;
  int type = 0;
  file.read(reinterpret_cast<char *>(&rows), sizeof(rows));
  file.read(reinterpret_cast<char *>(&cols), sizeof(cols));
  file.read(reinterpret_cast<char *>(&channels), sizeof(channels));
  file.read(reinterpret_cast<char *>(&type), sizeof(type));
  cv::Mat m(rows, cols, type, cv::Scalar(0, 0, 0));
  file.read(reinterpret_cast<char *>(m.data), GetDataSize(m));
  return m;
}

size_t GetDataSize(const cv::Mat &m) {
  size_t size = 0;
  switch(m.type()) {
    case CV_8UC1:
    case CV_8UC2:
    case CV_8UC3:
      size = sizeof(uchar);
      break;
    case CV_16UC1:
    case CV_16UC2:
    case CV_16UC3:
      size = sizeof(ushort);
      break;
    case CV_32FC1:
    case CV_32FC2:
    case CV_32FC3:
      size = sizeof(float);
      break;
    case CV_64FC1:
    case CV_64FC2:
    case CV_64FC3:
      size = sizeof(double);
      break;
    default:
      std::cerr << "Mat type not supported.\n";
  }
  return m.rows * m.cols * m.channels() * size;
}


cv::Mat Read(const std::string &filename) { return cv::imread(filename); }

void Show(const cv::Mat &m) {
  cv::imshow("Display", m);
  cv::waitKey(0);
}

} // namespace ipb::serialization
