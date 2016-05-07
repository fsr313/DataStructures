#include <iostream>

#include "heap.hpp"

int main() {
  heap A;
  A.add(5);
  A.add(6);
  A.add(7);
  A.add(4);
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  A.add(17);
  A.add(130);
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  std::cout << "popping smallest node: " << A.popfirst() << std::endl;
  A.print();
  return 0;
}
