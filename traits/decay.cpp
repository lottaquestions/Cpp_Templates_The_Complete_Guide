#include <iostream>
#include <typeinfo>
#include <type_traits>
#include "decay.hpp"


template<typename T>
void printDecayedType(){
  using A = typename DecayT<T>::Type;
  std::cout << "Parameter type: " << typeid(A).name() << std::endl;
  std::cout << " - is int: " << std::is_same<A, int>::value << std::endl;
  std::cout << " - is const: " << std::is_const<A>::value << std::endl;
  std::cout << " - is pointer: " << std::is_pointer<A>::value << std::endl;
  
}

int main(){
  printDecayedType<int>();
  printDecayedType<int const>();
  printDecayedType<int[7]>();
  printDecayedType<int(int)>();

  return 0;
}
