#pragma once

#include "path.hpp"

#include <filesystem>

class FirstRun {
public:
  static void Run() {
    std::cout << "\nFitstRun test:\n";
    copy_data();
  }

private:
  static void copy_data() {
    auto dest_dir =
        std::filesystem::path(path::GetProgramDataPath()) / "tonghao";
    std::filesystem::create_directory(dest_dir);

    for (const auto file : {"hello_msix.pdb"}) {
      auto src = std::filesystem::path(path::GetExecutableDirectory()) / file;
      std::filesystem::copy_file(src, dest_dir / file);
    }
  }
};