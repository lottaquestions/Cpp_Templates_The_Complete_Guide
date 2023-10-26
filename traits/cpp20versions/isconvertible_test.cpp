#include "isconvertible.hpp"
#include <string>
#include <iostream>

// To compile: /home/<username>/Software/gcc13.2/installation/bin/g++-13.2 -std=c++20 -g3  isconvertible.hpp isconvertible_test.cpp -o isconvertible_test.bin
// To use LD_LIBRARY_PATH=/home/<username>/Software/gcc13.2/installation/lib64 ./isconvertible_test.bin

void printHelper(std::string inputString, bool isConvertibleResult){
  std::cout << inputString << (isConvertibleResult? " is possible" : " is not possible") << std::endl;
}

int main(){

  printHelper("int to int conversion ", is_convertible<int,int>::value);
  printHelper("int to string conversion ", is_convertible<int,std::string>::value);
  printHelper("char const* to std::string conversion ", is_convertible<char const*, std::string>::value);
  printHelper("std::string to char const* conversion ", is_convertible<std::string, char const*>::value);
  return 0;
}
