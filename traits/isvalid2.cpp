#include "isvalid.hpp"

#include <iostream>
#include <string>
#include <utility>

// To compile: g++ -std=c++17 -g3  isvalid.hpp isvalid2.cpp -o isvalid2.bin

constexpr auto hasFirst = isValid([](auto&& x) -> decltype((void)&x.first){
				  });

template<typename T>
using HasFirstT = decltype(hasFirst(std::declval<T>()));


constexpr auto hasSizeType = isValid([](auto&& x) -> typename std::decay_t<decltype(x)>::size_type{} );

template<typename T>
using HasSizeTypeT = decltype(hasSizeType(std::declval<T>()));


constexpr auto hasLess = isValid([](auto&& x, auto&& y) -> decltype(x < y){});

template<typename T1, typename T2>
using HasLessT = decltype(hasLess(std::declval<T1>(), std::declval<T2>()));

int main(){
  using namespace std;

  cout << "first (pair): " << HasFirstT<pair<int,int>>::value << endl; // true

  struct CX{
    using size_type = std::size_t;
  };

  cout << "size_type (CX): " << HasSizeTypeT<CX>::value << endl; // true
  cout << "size_type (int): " << HasSizeTypeT<int>::value << endl; // false

  cout << "HasLessT<int, char>::value: " << HasLessT<int, char>::value << endl; //true
  cout << "HasLessT<string, string>::value: " << HasLessT<string, string>::value << endl; //true
  cout << "HasLessT<string, int>::value: " << HasLessT<string, int>::value << endl; //false
  cout << "HasLessT<string, char*>::value: " << HasLessT<string, char*>::value << endl; //true
  
  return 0;
}

