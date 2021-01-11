#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

namespace file {

const auto full_path = "C:\\Program Files\\msix.txt";
const auto file_content = R"(This is a test for msix from Tonghao.Yuan.hello)";

void WriteToFile() {
  std::cout << "test for writing to file:" << full_path << std::endl;
  std::ofstream test_file(full_path);
  if (!test_file.is_open()) {
    std::cerr << "can't open " << full_path << std::endl;
  }

  test_file << file_content;

  std::cout << "write file completed" << std::endl;
}

void ReadFile() {
  std::cout << "test for reading file:" << full_path << std::endl;
  std::ifstream test_file(full_path);
  if (!test_file.is_open()) {
    std::cerr << "can't open " << full_path << std::endl;
  }

  std::stringstream ss;
  while (test_file >> ss.rdbuf()) {
    // do nothing
  }

  if (ss.str() == file_content) {
    std::cout << "passed" << std::endl;
  } else {
    std::cerr << "failed" << std::endl;
  }
}

} // namespace file
