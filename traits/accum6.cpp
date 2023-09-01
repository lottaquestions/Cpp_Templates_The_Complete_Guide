#include "accum6.hpp"
#include <iostream>

// Compile with:
//     g++ -std=c++17 accumtraits3.hpp accum6.hpp accum6.cpp -o accum6.bin


class MultiPolicy{
public:
  template<typename T1, typename T2>
  static void accumulate(T1& total, T2& value){
    total *= value;
  }
};

int main(){
  // Create array of 5 integer values
  int num[] = {1,2,3,4,5};

  // Print average value
  std::cout << "The average value of the integer values is " << accum(num, num+5)/5 << std::endl;

  // Print product of integer values. Note there is a bug in this one as the initial accumulator value is zero instead of 1
  std::cout << "The product of the integer values is (wrong due to zero init acccumulator value) "
	    << accum<int,MultiPolicy>(num, num+5)
	    << std::endl;

  char name[] = "templates";
  int length = sizeof(name)-1;
  
  // Try to print the average character value
  std::cout << "The average of the characters in \"" << name << "\" is " << accum(name, name+length)/length << std::endl;

  return 0;
}
