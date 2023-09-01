#include "accum2.hpp"
#include <iostream>

// Compile with:
//     g++ -std=c++17 accumtraits2.hpp accum2.hpp accum2.cpp -o accum2.bin

int main(){
  // Create array of 5 integer values
  int num[] = {1,2,3,4,5};

  // Print average value
  std::cout << "The average value of the integer values is " << accum(num, num+5)/5 << std::endl;

  char name[] = "templates";
  int length = sizeof(name)-1;
  
  // Try to print the average character value
  std::cout << "The average of the characters in \"" << name << "\" is " << accum(name, name+length)/length << std::endl;

  return 0;
}
