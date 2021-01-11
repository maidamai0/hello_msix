#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "path.hpp"

namespace {
const auto file_name = "msix.txt";
const auto file_content = R"(This is a test for msix from Tonghao.Yuan.hello)";
} // namespace

class file {

public:
  static void RunTest() {
    std::cout << "\nFile test:" << std::endl;
    Test(path::GetAppDataPath());
    Test(path::GetRedirectAppDataPath());
  }

private:
  static void Test(std::string &&path) {
    const auto full_path = path + "\\" + file_name;
    WriteToFile(full_path);
    ReadFile(full_path);
  }

  void static WriteToFile(const std::string &full_path) {
    std::cout << "test for writing to file:" << full_path;
    std::ofstream test_file(full_path);
    if (!test_file.is_open()) {
      std::cerr << ", open failed" << std::endl;
      return;
    }

    test_file << file_content;

    std::cout << ", completed" << std::endl;
  }

  void static ReadFile(const std::string &full_path) {
    std::cout << "test for reading file:" << full_path;
    std::ifstream test_file(full_path);
    if (!test_file.is_open()) {
      std::cerr << ", open failed" << std::endl;
      return;
    }

    std::stringstream ss;
    while (test_file >> ss.rdbuf()) {
      // do nothing
    }

    if (ss.str() == file_content) {
      std::cout << ", passed" << std::endl;
    } else {
      std::cerr << ", failed" << std::endl;
    }
  }
};
