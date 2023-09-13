#include "issame.hpp"
#include <iostream>

// To compile: g++ -std=c++17 -g3 boolconstant.hpp issame.hpp issame.cpp -o issame.bin

template<typename T>
void fooImpl(T, TrueType){
  std::cout << "fooImpl(T, true) for int called\n";
}

template<typename T>
void fooImpl(T, FalseType){
  std::cout << "fooimpl(T, false) for other types called\n";
}

template<typename T>
void foo(T t){
  fooImpl(t, IsSameT<T,int>{}); // Choose implementation depending on whether T is int
}


int main(){
  foo(42); // Calls fooimpl(42, TrueType)
  foo(7.7); // Calls fooimpl(7.7, FalseType)
  // This technique is called tag dispatching

  return 0;
}
