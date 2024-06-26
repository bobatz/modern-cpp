#include "html_writer.hpp"
#include "fmt/core.h"
#include <filesystem>
#include <string>

namespace html_writer {
void OpenDocument() { fmt::print("<!DOCTYPE html>\n<html>\n"); }

void CloseDocument() { fmt::print("</html>\n"); }

void AddCSSStyle(const std::string &stylesheet) {
  fmt::print("<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" />\n",
             stylesheet);
}

void AddTitle(const std::string &title) {
  fmt::print("  <title>{}</title>\n", title);
}

void OpenBody() { fmt::print("  <body>\n"); }

void CloseBody() { fmt::print("  </body>\n"); }

void OpenRow() { fmt::print("    <div class=\"row\">\n"); }

void CloseRow() { fmt::print("    </div>\n"); }

void AddImage(const std::string &img_path, float score, bool highlight) {
  std::string filename = std::filesystem::path(img_path).filename();
  std::string ext = std::filesystem::path(img_path).extension();
  if (ext != ".png" && ext != ".jpg") {
    fmt::print(stderr, "Image must be a png or jpg file.\n");
    return;
  }
  std::string borderStyle = "";
  if (highlight) {
    borderStyle = " style=\"border: 5px solid green;\"";
  }
  fmt::print("      <div class=\"column\" {}>\n", borderStyle);
  fmt::print("        <h2>{}</h2>\n", filename);
  fmt::print("        <img src=\"{}\" />\n", img_path);
  fmt::print("        <p>score = {:.2f}</p>\n", score);
  fmt::print("      </div>\n");
}

} // namespace html_writer
