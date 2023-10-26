#include "isvalid.hpp"
#include <iostream>
#include <string>
#include <utility>

// To compile: g++ -std=c++17 -g3  isvalid.hpp isvalid1.cpp -o isvalid1.bin

int main(){
  using namespace std;
  cout << boolalpha;
  // Define to check for data member first
  constexpr auto hasFirst = isValid([](auto x) -> decltype((void) valueT(x).first){
				    });
  
  cout << "hasFirst: " << hasFirst(type<pair<int,int>>) << endl; // True

  // Define to check for member type size_type
  constexpr auto hasSizeType = isValid([](auto x) -> typename decltype(valueT(x))::size_type {
				       });

  struct CX{
    using size_type = std::size_t;
  };
  cout << "hasSizeType: " << hasSizeType(type<CX>) << endl; // True
  if constexpr (!hasSizeType(type<int>)){
      cout << "int has not size_type" << endl;
  }
  // Define check for <
  constexpr auto hasLess = isValid([](auto x, auto y) -> decltype(valueT(x) < valueT(y) ) {
				   });
  cout << hasLess(42, type<char>) << endl ; // yields true . Returned false at runtime
  cout << hasLess(type<string>, type<string>) << endl; //yields true. Note!!: Only this one returned true as expected when run!
  cout << hasLess(type<string>, type<int> ) << endl; // yields false
  cout << hasLess(type<string>, "hello") << endl; // yields true . This returned false at runtime

  return 0;
}
