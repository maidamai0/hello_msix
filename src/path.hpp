#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <ShlObj_core.h>

class path {

public:
  void static RunTest() {
    std::cout << "\nPath test:" << std::endl;
    std::cout << "Local appdata             :" << GetAppDataPath() << std::endl;
    std::cout << "Local appdata(container)  :" << GetRedirectAppDataPath()
              << std::endl;

    std::cout << "Current directory from std:"
              << std::filesystem::current_path() << std::endl;

    std::cout << "Current directory from win:" << get_current_directory()
              << std::endl;

    std::cout << "Current directory from exe:" << GetExecutableDirectory()
              << std::endl;

    std::cout << "read modification_test: " << read_modification_test()
              << std::endl;
  }

  std::string static GetAppDataPath() {
    PWSTR dest_path = {};
    SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, 0, &dest_path);
    std::string ret = Ws2s(std::wstring(dest_path));
    CoTaskMemFree(dest_path);

    return ret;
  }

  std::string static GetRedirectAppDataPath() {
    PWSTR dest_path = {};
    SHGetKnownFolderPath(FOLDERID_LocalAppData,
                         KF_FLAG_FORCE_APPCONTAINER_REDIRECTION, 0, &dest_path);
    std::string ret = Ws2s(std::wstring(dest_path));
    CoTaskMemFree(dest_path);

    return ret;
  }

  std::string static GetProgramDataPath() {
    PWSTR dest_path = {};
    SHGetKnownFolderPath(FOLDERID_ProgramData, 0, 0, &dest_path);
    std::string ret = Ws2s(std::wstring(dest_path));
    CoTaskMemFree(dest_path);

    return ret;
  }

  std::string static GetRedirectProgramDataPath() {
    PWSTR dest_path = {};
    SHGetKnownFolderPath(FOLDERID_ProgramData,
                         KF_FLAG_FORCE_APPCONTAINER_REDIRECTION, 0, &dest_path);
    std::string ret = Ws2s(std::wstring(dest_path));
    CoTaskMemFree(dest_path);

    return ret;
  }

  static std::string GetExecutableDirectory() {
    TCHAR buffer[MAX_PATH];
    DWORD dwRet = GetModuleFileName(NULL, buffer, sizeof(buffer));

    if (dwRet == 0) {
      std::cerr << "GetCurrentDirectory failed" << std::endl;
      return {};
    }

    return std::filesystem::path(buffer).parent_path().string();
  }

private:
  static std::string Ws2s(std::wstring &&wstr) {
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0],
                                          (int)wstr.length(), 0, 0, 0, 0);
    std::string str_to(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.length(), &str_to[0],
                        size_needed, NULL, NULL);
    return str_to;
  }

  static std::string get_current_directory() {
    TCHAR buffer[MAX_PATH];
    DWORD dwRet = GetCurrentDirectory(MAX_PATH, buffer);

    if (dwRet == 0) {
      std::cerr << "GetCurrentDirectory failed" << std::endl;
      return {};
    }

    return std::string(buffer);
  }

  static std::string read_modification_test() {
    std::ifstream file("modification_test");
    if (!file.is_open()) {
      return {"open failed"};
    }

    std::stringstream ss;
    while (file >> ss.rdbuf()) {
    }

    return ss.str();
  }
};
