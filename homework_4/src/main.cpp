#include "homework_4.h"

int main() {
  ipb::named_vector<int> nv = {"A named vector", std::vector(10, 0)};
  ipb::print(nv);
  return 0;
}
