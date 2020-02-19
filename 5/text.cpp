#include <iostream>
#include <limits>

int main() {
  std::cout << "Press Enter to Continue" << std::endl;
  std::cin.sync();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}