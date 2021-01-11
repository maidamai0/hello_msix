#pragma once

#include <iostream>
#include <string>

#include <ShlObj_core.h>

class path {

public:
  void static RunTest() {
    std::cout << "\nPath test:" << std::endl;
    std::cout << "Local appdata             :" << GetAppDataPath() << std::endl;
    std::cout << "Local appdata(container)  :" << GetRedirectAppDataPath()
              << std::endl;
  }

  std::string static GetAppDataPath() {
    PWSTR local_appdata = {};
    SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, 0, &local_appdata);
    std::string ret = Ws2s(std::wstring(local_appdata));
    CoTaskMemFree(local_appdata);

    return ret;
  }

  std::string static GetRedirectAppDataPath() {
    PWSTR local_appdata = {};
    SHGetKnownFolderPath(FOLDERID_LocalAppData,
                         KF_FLAG_FORCE_APPCONTAINER_REDIRECTION, 0,
                         &local_appdata);
    std::string ret = Ws2s(std::wstring(local_appdata));
    CoTaskMemFree(local_appdata);

    return ret;
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
};
