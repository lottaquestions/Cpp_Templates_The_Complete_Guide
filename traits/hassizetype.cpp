#include "hassizetype.hpp"
#include <iostream>

// To compile: g++ -std=c++17 removereference.hpp hassizetype.hpp hassizetype.cpp -o hassizetype.bin

int main(){
  struct CX{
    using size_type = std::size_t;
  };

  std::cout << HasSizeTypeT<CX>::value << std::endl;
  std::cout << HasSizeTypeT<int>::value << std::endl;
}
