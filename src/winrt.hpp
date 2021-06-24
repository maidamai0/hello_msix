#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#define _SILENCE_CLANG_COROUTINE_MESSAGE
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Management.Deployment.h>
#include <winrt/Windows.Storage.h>

class WinRT {
 public:
  static auto Run() {
    std::cout << "\nWinRT test:\n";
    print_all_packages();
    package_path("Tonghao.Yuan.hello");
  }

 private:
  /**
   * @brief Find install path with the identity name specified in
   * appxmanifest.xml
   *
   * @param identity_name
   */
  static std::string package_path(const std::string& identity_name) {
    using namespace winrt::Windows::Management;
    winrt::init_apartment();
    // TODO (tonghao): 2021-06-24
    // FindPackagesByNamePublisher maybe a better fit, didn't figure out what
    // the parameter means
    // MicroSoft is stupid
    for (const auto& package : Deployment::PackageManager{}.FindPackages()) {
      const auto name = winrt::to_string(package.Id().Name());
      if (name.find(identity_name) != std::string::npos) {
        std::wcout << "Application Found:\n";
        print_package(package);
        return winrt::to_string(package.InstalledLocation().Path());
      }
    }

    return std::string{};
  }

  static void print_all_packages() {
    winrt::init_apartment();
    using namespace winrt::Windows::Management;
    for (const auto& package : Deployment::PackageManager{}.FindPackages(
             L"Tonghao.Yuan.hello",
             L" CN=Tonghao, O=Tonghao, L=Shanghai, S=Shanghai, C=China")) {
      print_package(package);
    }
  }

  static void print_package(
      const winrt::Windows::ApplicationModel::Package& package) {
    try {
      std::wcout << L"Name: " << package.Id().Name().c_str() << std::endl;
      std::wcout << L"FullName: " << package.Id().FullName().c_str()
                 << std::endl;
      std::wcout << L"Version: " << package.Id().Version().Major << "."
                 << package.Id().Version().Minor << "."
                 << package.Id().Version().Build << "."
                 << package.Id().Version().Revision << std::endl;
      std::wcout << L"Publisher: " << package.Id().Publisher().c_str()
                 << std::endl;
      std::wcout << L"PublisherId: " << package.Id().PublisherId().c_str()
                 << std::endl;
      std::wcout << L"Installed Location: "
                 << package.InstalledLocation().Path().c_str() << std::endl;
      std::wcout << L"IsFramework: "
                 << (package.IsFramework() ? L"True" : L"False") << std::endl;
    } catch (winrt::hresult_error const& ex) {
      std::wcout << ex.message().c_str() << std::endl;
    }
  }
};
