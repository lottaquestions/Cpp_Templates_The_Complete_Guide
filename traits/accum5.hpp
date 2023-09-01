#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits3.hpp"

// Example of a parametized trait.
template<typename T, typename AT = AccumulationTraits<T>>
auto accum(T const* beg, T const* end){
  
  typename AT::AccT total = AT::zero;// Init total by trait value

  while(beg != end){
    total += *beg;
    ++beg;
  }
  return total;
}

#endif // ACCUM_HPP
