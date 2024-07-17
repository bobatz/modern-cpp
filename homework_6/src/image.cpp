#include "image.hpp"
#include "io_tools.hpp"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using igg::io_tools::ImageData;
using igg::Image;

Image::Image() : rows_(0), cols_(0), data_(std::vector<uint8_t>()) {}

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(std::vector<uint8_t>(rows * cols, 0)) {}

int Image::rows() const { return rows_; }

int Image::cols() const { return cols_; }

uint8_t &Image::at(int row, int col) { return data_[row * cols_ + col]; }

const uint8_t &Image::at(int row, int col) const { return data_[row * cols_ + col]; }

bool Image::FillFromPgm(const std::string &file_name) {
  ImageData image_data = igg::io_tools::ReadFromPgm(file_name);
  rows_ = image_data.rows;
  cols_ = image_data.cols;
  data_ = std::move(image_data.data);
  return true;
}

void Image::WriteToPgm(const std::string &file_name) {
  std::vector<uint8_t>::iterator max_val =
      std::max_element(data_.begin(), data_.end());
  const ImageData image_data = {rows_, cols_, *max_val, data_};
  igg::io_tools::WriteToPgm(image_data, file_name);
}

const std::vector<float> Image::ComputeHistogram(int bins) const {
  if (data_.size() == 0) {
    return std::vector<float>(1, 1);
  }
  std::vector<float> counts(bins, 0);
  float bin_size = 255.0f / bins;
  std::vector<float> thresholds;
  for (int i = 0; i < bins; i++) {
    thresholds.emplace_back((i + 1) * bin_size);
  }
  for (int i = 0; i < data_.size(); i++) {
    for (int j = 0; j < thresholds.size(); j++) {
      if (data_[i] <= thresholds[j]) {
        counts[j] += 1.0f;
        break;
      }
    }
  }
  for (int i = 0; i < counts.size(); i++) {
    counts[i] = counts[i] / data_.size();
  }
  return counts;
}

void Image::DownScale(int scale) {
  int r2 = rows_ / scale;
  int c2 = cols_ / scale;
  std::vector<uint8_t> data2(r2 * c2, 0);
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      data2[i * c2 + j] = at(i * scale, j * scale);
    }
  }
  rows_ = r2;
  cols_ = c2;
  data_ = data2;
}

void Image::UpScale(int scale) {
  int r2 = rows_ * scale;
  int c2 = cols_ * scale;
  std::vector<uint8_t> data2(r2 * c2, 0);
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      data2[i * c2 + j] = at(i / scale, j / scale);
    }
  }
  rows_ = r2;
  cols_ = c2;
  data_ = data2;
}
