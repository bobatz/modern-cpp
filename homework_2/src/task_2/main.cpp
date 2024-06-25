#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

bool streamArgument(const char* s, int& num, std::string& ext) {
  std::stringstream ss{s};
  ss >> num >> ext;
  if (ss.fail()) {
    ss.clear();
    return false;
  }
  return true;
}

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    std::cerr << "Did not receive exactly 2 input arguments.\n";
    return EXIT_FAILURE;
  }
  int num1;
  int num2;
  std::string ext1;
  std::string ext2;
  if (!streamArgument(argv[1], num1, ext1) ||
      !streamArgument(argv[2], num2, ext2)) {
    std::cerr << "One or more arguments did not match the format.\n";
    return EXIT_FAILURE;
  }
  if (ext1.compare(".txt") == 0) {
    if (ext2.compare(".txt") == 0) {
      std::cout << (num1 + num2) / 2 << std::endl;
      return EXIT_SUCCESS;
    }
    else if (ext2.compare(".png") == 0) {
      std::cout << num1 % num2 << std::endl;
      return EXIT_SUCCESS;
    }
  }
  else if (ext1.compare(".png") == 0 && ext2.compare(".png") == 0) {
    std::cout << num1 + num2 << std::endl;
    return EXIT_SUCCESS;
  }
  std::cerr << "File extensions did not match any case.\n";
  return EXIT_FAILURE;
}
