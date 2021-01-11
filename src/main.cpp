#include <iostream>

#include "file.hpp"
#include "path.hpp"
#include "signal.hpp"

int main() {
  signal::CatcureSignal();

  std::cout << "Hello, this app is installed with msix" << std::endl;

  // test path
  path::RunTest();

  // test file
  file::RunTest();

  std::cin.get();
}