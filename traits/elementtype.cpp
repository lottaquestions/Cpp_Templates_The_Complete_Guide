#include "elementtype.hpp"
#include <iostream>
#include <typeinfo>

// To compile:
//   g++ -std=c++17 elementtype.hpp elementtype.cpp -o elementtype.bin

template<typename T>
void printElementType(T const& c){
  std::cout << "Container of "
	    << typeid(typename ElementT<T>::Type).name()
	    << " elements"
	    << std::endl;
}


int main(){
  std::vector<bool> s;
  printElementType(s);
  int arr[42];
  printElementType(arr);
}
