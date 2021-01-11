#include <iostream>

#include "file.hpp"
#include "signal.hpp"

int main() {
  signal::CatcureSignal();

  std::cout << "Hello, this app is installed with msix" << std::endl;

  // test write to file
  file::WriteToFile();

  // test read file
  file::ReadFile();

  std::cin.get();
}