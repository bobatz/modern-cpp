#include <iostream>

int main() {
  std::cout << "[STANDARD OUTPUT] Enter an integer." << std::endl;
  int num;
  std::cin >> num;
  std::cerr << "[STANDARD ERROR] Default error message." << std::endl;
  return 0;
}
