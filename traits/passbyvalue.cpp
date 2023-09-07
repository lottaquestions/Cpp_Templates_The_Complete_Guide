#include <iostream>
#include <typeinfo>
#include <type_traits>

template<typename T>
void f(T){}

template<typename A>
void printParameterType(void (*) (A)){
  std::cout << "Parameter type " << typeid(A).name()  << std::endl;
  std::cout << "- is int:      " << std::is_same<A, int>::value << std::endl;
  std::cout << "- is const:    " << std::is_const<A>::value << std::endl;
  std::cout << "- is pointer:  " << std::is_pointer<A>::value << std::endl;
}


int main(){
  printParameterType(&f<int>);
  printParameterType(&f<int const>);
  printParameterType(&f<int[7]>);
  printParameterType(&f<int(int)>);

  return 0;
}
