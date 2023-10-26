#include "hasmember.hpp"
#include <iostream>
#include <vector>
#include <utility>

// To compile: g++ -std=c++17 hasmember.hpp hasmember.cpp -o hasmember.bin

DEFINE_HAS_MEMBER(size);
DEFINE_HAS_MEMBER(first);

int main(){
  std::cout << "int::size " << HasMemberT_size<int>::value << std::endl;
  std::cout << "std::vector<int>::size: " << HasMemberT_size<std::vector<int>>::value << std::endl;
  std::cout << "std::pair<int,int>::first: " << HasMemberT_first<std::pair<int,int>>::value << std::endl;
  return 0;
}
