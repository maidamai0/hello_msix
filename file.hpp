#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

namespace file {

const auto full_path = "C:\\ProgramData\\TW\\AcqAltair\\appx.txt";
const auto file_content = R"(This is a test for msix from Tonghao.Yuan.hello)";

void WriteToFile() {
  std::cout << "test for writing to file:" << full_path << std::endl;
  std::ofstream appx_preference(full_path);
  if (!appx_preference.is_open()) {
    std::cerr << "can't open " << full_path << std::endl;
  }

  appx_preference << file_content;

  std::cout << "write file completed" << std::endl;
}

void ReadFile() {
  std::cout << "test for reading file:" << full_path << std::endl;
  std::ifstream appx_preference(full_path);
  if (!appx_preference.is_open()) {
    std::cerr << "can't open " << full_path << std::endl;
  }

  std::stringstream ss;
  while (appx_preference >> ss.rdbuf()) {
    // do nothing
  }

  if (ss.str() == file_content) {
    std::cout << "passed" << std::endl;
  } else {
    std::cerr << "failed" << std::endl;
  }
}

} // namespace file
