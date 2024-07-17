#include "image.hpp"
#include "io_tools.hpp"
#include <iostream>
#include <vector>

using igg::Image;

int main() {
  std::cout << "Hello world!\n";

  // Default initialization
  auto image1 = Image();

  // Initialization with rows and cols
  auto image2 = Image(2, 2);

  // Write a new value to an element
  std::cout << "---Image 2 contents---\n";
  image2.at(0, 1) = 130;
  image2.at(1, 1) = 255;
  for (int i = 0; i < image2.rows(); i++) {
    for (int j = 0; j < image2.cols(); j++) {
      std::cout << "(" << i << ", " << j << "): " << +image2.at(i, j) << std::endl;
    }
  }

  // Histogram
  std::cout << "---Dummy image histogram---\n";

  Image image;
  image.FillFromPgm("/home/amarbold/courses/modern-cpp/homework_6/tests/data/dummy_file.pgm");
  const auto& image_ref = image;
  int size = 10;
  auto histogram = image_ref.ComputeHistogram(size);
  std::cout << "Histogram size: " << histogram.size() << std::endl;
  for (int i = 0; i < histogram.size(); i++) {
    std::cout << i << ": " << histogram[i] << std::endl;
  }

  // Read and write files
  Image image3;
  image3.FillFromPgm("/home/amarbold/courses/modern-cpp/homework_6/data/lena.ascii.pgm");
  image3.WriteToPgm("/home/amarbold/courses/modern-cpp/homework_6/data/test_write.pgm");
  image3.DownScale(2);
  image3.WriteToPgm("/home/amarbold/courses/modern-cpp/homework_6/data/test_downscale.pgm");
  image3.UpScale(4);
  image3.WriteToPgm("/home/amarbold/courses/modern-cpp/homework_6/data/test_upscale.pgm");

  //
  //auto imageData = igg::io_tools::ReadFromPgm("/home/amarbold/courses/modern-cpp/homework_6/data/lena.ascii.pgm");
  //igg::io_tools::WriteToPgm(imageData, "/home/amarbold/courses/modern-cpp/homework_6/data/test.pgm");

  return 0;
}
