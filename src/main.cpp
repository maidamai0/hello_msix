#include <iostream>

#include "file.hpp"
#include "first_run.hpp"
#include "path.hpp"
#include "signal.hpp"
#include "winrt.hpp"

int main() {
  signal::CatcureSignal();

  std::cout << "Hello, this app is installed with msix" << std::endl;

  // test path
  path::RunTest();

  // test file
  file::RunTest();

  // preparation
  FirstRun::Run();

  // WinRT
  WinRT::Run();

  std::cin.get();
}