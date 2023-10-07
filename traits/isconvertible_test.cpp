#include "isconvertible.hpp"
#include <string>
#include <iostream>

// To compile: g++ -std=c++17 -g3  isconvertible.hpp isconvertible_test.cpp -o isconvertible_test.bin

void printHelper(std::string inputString, bool isConvertibleResult){
  std::cout << inputString << (isConvertibleResult? " is possible" : " is not possible") << std::endl;
}

int main(){
  /*
  printHelper("int to int conversion ", IsConvertible<int,int>::value);
  printHelper("int to string conversion ", IsConvertible<int,std::string>::value);
  printHelper("char const* to std::string conversion ", IsConvertible<char const*, std::string>::value);
  printHelper("std::string to char const* conversion ", IsConvertible<std::string, char const*>::value);
  */

  printHelper("int to int conversion ", isConvertible<int,int>);
  printHelper("int to string conversion ", isConvertible<int,std::string>);
  printHelper("char const* to std::string conversion ", isConvertible<char const*, std::string>);
  printHelper("std::string to char const* conversion ", isConvertible<std::string, char const*>);
  return 0;
}
