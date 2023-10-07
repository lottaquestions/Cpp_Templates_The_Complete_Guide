#include "isdefaultconstructible1.hpp"
#include <iostream>

// To compile: g++ -std=c++17 -g3 boolconstant.hpp issame.hpp isdefaultconstructible1.hpp isdefaultconstructible1.cpp -o isdefaultconstructible1.bin

struct S{S()=delete;};

int main(){
  bool isInt{IsDefaultConstructibleT<int>::value};
  bool notConstructible{!IsDefaultConstructibleT<S>::value};

  if (isInt)
    std::cout << "int is default constructible" << std::endl; 
  if (notConstructible)
    std::cout <<"S is not default constructible" << std::endl;

  return 0;
}
