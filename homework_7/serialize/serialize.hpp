// @file      serialize.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <string>

#include <opencv2/core/mat.hpp>

namespace ipb::serialization {

/**
 * @brief Writes the input cv::Mat(Image, SIFT, etc) to a binary file
 *
 * @param m        The input cv::Mat you want to serialize.
 * @param filename The filename of the file where the cv::Mat will be written.
 */
void Serialize(const cv::Mat &m, const std::string &filename);

/**
 * @brief Reads a binary file representing a cv::Mat type and outputs the
 * contetnt of this file into a new cv::Mat
 *
 * @param filename The binary file you want to read
 * @return cv::Mat The cv::Mat created from the binary file
 */
cv::Mat Deserialize(const std::string &filename);

/**
 * @brief Measures the size of the data buffer of a cv::Mat.
 *
 * @param m        The input cv::Mat
 * @return size_t  The size of the data buffer.
 */
size_t GetDataSize(const cv::Mat &m);

cv::Mat Read(const std::string &filename);

void Show(const cv::Mat &m);

} // namespace ipb::serialization

#endif // SERIALIZE_HPP_
