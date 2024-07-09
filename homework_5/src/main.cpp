#include "convert_dataset.hpp"
#include "serialize.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[]) {
  cv::Mat m = ipb::serialization::Read("data/lenna.png");
  std::cout << "Rows: " << m.rows << std::endl;
  std::cout << "Cols: " << m.cols << std::endl;
  std::cout << "Type: " << m.type() << std::endl;
  ipb::serialization::Serialize(m, "data/serialized_lenna.bin");
  cv::Mat result = ipb::serialization::Deserialize("data/serialized_lenna.bin");
  std::cout << "Rows: " << result.rows << std::endl;
  std::cout << "Cols: " << result.cols << std::endl;
  std::cout << "Type: " << result.type() << std::endl;
  ipb::serialization::Show(result);

  std::filesystem::path img_path("data/freiburg/images");
  std::filesystem::path bin_path("data/freiburg/bin");
  ipb::serialization::sifts::ConvertDataset(img_path);
  std::vector<cv::Mat> dataset =
      ipb::serialization::sifts::LoadDataset(bin_path);

  return 0;
}
