#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits3.hpp"
#include "sumpolicy2.hpp"

// Example of a policy and a parametized trait.
template<typename T,
	 template<typename,typename> class Policy = SumPolicy,
	 typename Traits = AccumulationTraits<T>>
auto accum(T const* beg, T const* end){

  using AccT = typename Traits::AccT;
  
  AccT total = Traits::zero;// Init total by trait value

  while(beg != end){
    Policy<AccT,T>::accumulate(total, *beg) ;
    ++beg;
  }
  return total;
}

#endif // ACCUM_HPP
