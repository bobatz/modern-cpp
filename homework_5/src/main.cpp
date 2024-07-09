#include "serialize.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  cv::Mat m = ipb::serialization::Read("/home/amarbold/courses/modern-cpp/homework_5/data/lenna.png");
  std::cout << "Rows: " << m.rows << std::endl;
  std::cout << "Cols: " << m.cols << std::endl;
  std::cout << "Type: " << m.type() << std::endl;
  ipb::serialization::Serialize(m, "/home/amarbold/courses/modern-cpp/homework_5/data/serialized_lenna.bin");
  cv::Mat result = ipb::serialization::Deserialize("/home/amarbold/courses/modern-cpp/homework_5/data/serialized_lenna.bin");
  std::cout << "Rows: " << result.rows << std::endl;
  std::cout << "Cols: " << result.cols << std::endl;
  std::cout << "Type: " << result.type() << std::endl;
  ipb::serialization::Show(result);
  return 0;
}
