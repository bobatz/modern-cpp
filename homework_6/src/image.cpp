#include "image.hpp"
#include <vector>

Image::Image() : rows_(0), cols_(0), data_(std::vector<int>()) {}

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(std::vector<int>(rows * cols, 0)) {}

int Image::rows() const { return rows_; }

int Image::cols() const { return cols_; }

int &Image::at(int row, int col) { return data_[row * cols_ + col]; }
