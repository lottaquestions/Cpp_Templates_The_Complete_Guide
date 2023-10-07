#include "isvalid.hpp"
#include <iostream>

// To compile: g++ -std=c++17 -g3  isvalid.hpp isdefaultconstructible.cpp -o isdefaultconstructible.bin

constexpr auto isDefaultConstructible
						= isValid([](auto x) -> decltype((void)decltype(valueT(x))()) {
            });					       
int main(){
  bool isIntDefaultConst = isDefaultConstructible(type<int>);
  bool isIntRefDefaultConst = isDefaultConstructible(type<int&>);

  if (isIntDefaultConst)
    std::cout<< "int is default constructible" << std::endl;

  if(!isIntRefDefaultConst)
    std::cout << "reference to int is not default constructible" << std::endl;

  return 0;
}
