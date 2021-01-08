#include <iostream>

int main() {
  std::cout << "Hello this app is installed with msix, what's your name?"
            << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << name << std::endl;
  std::cout << "press any key to close this" << std::endl;
  std::cin >> name;
}