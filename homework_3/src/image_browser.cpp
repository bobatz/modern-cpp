#include "image_browser.hpp"
#include "html_writer.hpp"
#include <array>
#include <string>
#include <tuple>
#include <vector>

namespace image_browser {
using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

void AddFullRow(const ImageRow &row, bool first_row) {
  html_writer::OpenRow();
  html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), first_row);
  html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
  html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);
  html_writer::CloseRow();
}

void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {
  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  for (int i = 0; i < rows.size(); i++) {
    bool first_row = i == 0;
    AddFullRow(rows.at(i), first_row);
  }
  html_writer::CloseBody();
  html_writer::CloseDocument();
}
} // namespace image_browser
