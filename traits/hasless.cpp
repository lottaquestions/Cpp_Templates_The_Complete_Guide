#include "hasless.hpp"
#include <iostream>
#include <complex>
#include <string>
#include <utility>

// To compile: g++ -std=c++17 hasless.hpp hasless.cpp -o hasless.bin


int main(){
  std::cout << "int < char: " << HasLessT<int, char>::value << std::endl;
  std::cout << "std::string < std::string: " << HasLessT<std::string, std::string>::value << std::endl;
  std::cout << "std::string < int: " << HasLessT<std::string, int>::value << std::endl;
  std::cout << "std::string < char*: " << HasLessT<std::string, char*>::value << std::endl;
  std::cout << "std::complex<double> < std::complex<double>: " << HasLessT<std::complex<double>, std::complex<double>>::value << std::endl;
  return 0;
}
