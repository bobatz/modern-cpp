#include "image_browser.hpp"

using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

int main() {
  ScoredImage t1 = std::make_tuple(
      "/home/amarbold/courses/modern-cpp/homework_3/web_app/data/000000.png",
      0.000f);
  ScoredImage t2 = std::make_tuple(
      "/home/amarbold/courses/modern-cpp/homework_3/web_app/data/000100.png",
      0.100f);
  ScoredImage t3 = std::make_tuple(
      "/home/amarbold/courses/modern-cpp/homework_3/web_app/data/000200.png",
      0.200f);
  ImageRow row{t1, t2, t3};
  std::vector<ImageRow> rows = {row, row, row};
  image_browser::CreateImageBrowser(
      "Title", "/home/amarbold/courses/modern-cpp/homework_3/web_app/style.css",
      rows);
  return 0;
}
