#include "image.hpp"
#include <iostream>

int main() {
  std::cout << "Hello world!\n";

  auto image1 = Image();
  auto image2 = Image(2, 3);
  std::cout << "Image 2 at (0, 0): " << image2.at(0, 0) << std::endl;
  image2.at(0, 0) = 1;
  std::cout << "Image 2 at (0, 0): " << image2.at(0, 0) << std::endl;
  return 0;
}
