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
    const auto preparation_log_path =
        std::filesystem::path(path::GetRedirectAppDataPath()) /
        "preparation_log";
    if (std::filesystem::exists(preparation_log_path)) {
      return;
    }

    auto dest_dir =
        std::filesystem::path(path::GetProgramDataPath()) / "tonghao";
    std::filesystem::create_directory(dest_dir);
    auto preparation_log = std::ofstream(preparation_log_path);

    try {
      for (const auto file : {"hello_msix.pdb"}) {
        preparation_log << "copy " << file;
        auto src = std::filesystem::path(path::GetExecutableDirectory()) / file;
        std::filesystem::copy_file(src, dest_dir / file);
        preparation_log << " complete." << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << "copy file failed: " << e.what() << std::endl;
      preparation_log.close();
      std::filesystem::remove(preparation_log_path);
    }
  }
};