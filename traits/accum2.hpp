#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits2.hpp"

template<typename T>
auto accum(T const* beg, T const* end){
  // Return type is traits of the element type
  using AccT = typename AccumulationTraits<T>::AccT;

  AccT total{}; // Assume this actually creates a zero value

  while(beg != end){
    total += *beg;
    ++beg;
  }
  return total;
}

#endif // ACCUM_HPP
