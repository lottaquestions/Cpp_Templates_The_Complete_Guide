#include "hastype.hpp"
#include <iostream>
#include <vector>

// To compile: // To compile: g++ -std=c++17 hastype.hpp hastype.cpp -o hastype.bin

DEFINE_HAS_TYPE(value_type);
DEFINE_HAS_TYPE(char_type);

int main(){
  std::cout << "int::value_type: " << HasTypeT_value_type<int>::value << std::endl;
  std::cout << "std::vector<int>::value_type: " << HasTypeT_value_type<std::vector<int>>::value << std::endl;
  std::cout << "std::iostream::value_type: " << HasTypeT_value_type<std::iostream>::value << std::endl;
  std::cout << "std::iostream::char_type: " << HasTypeT_char_type<std::iostream>::value << std::endl;

  return 0;
}
