#include "hasbegin.hpp"
#include <iostream>
#include <vector>
#include <utility>

// To compile: g++ -std=c++17 hasbegin.hpp hasbegin.cpp -o hasbegin.bin


int main(){
  std::cout << "int: " << HasBeginT<int>::value << std::endl;
  std::cout << "std::vector<int>: " << HasBeginT<std::vector<int>>::value << std::endl;
  std::cout << "std::pair<int,int>: " << HasBeginT<std::pair<int,int>>::value << std::endl;
  return 0;
}
