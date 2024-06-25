#include <iostream>
#include <random>
#include <cstdlib>

int main() {
  std::random_device rd;
  int min = 0;
  int max = 99;
  std::uniform_int_distribution<int> dist(min, max);
  int num = dist(rd);
  int result = EXIT_FAILURE;
  while (true) {
    int guess;
    std::cin >> guess;

    // Extraction failed.
    if (std::cin.fail()) {
      std::cerr << "Error encountered, exiting...\n";
      break;
    }

    if (guess < min || guess > max) {
      std::cerr << "[WARNING] : Number must be between 0 and 99\n";
      break;
    }
    if (guess < num) {
      std::cout << "Number is larger.\n";
    }
    else if (guess > num) {
      std::cout << "Number is smaller.\n";
    }
    else {
      result == EXIT_SUCCESS;
      break;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout << num << "\n";
  return result;
}
