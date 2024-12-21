#ifndef IFTHENELSE_HPP
#define IFTHENELSE_HPP

// Note that after C++14 this functionality is provided by std::condotional_t

// primary template: yield the second argument by default and rely on a partial specialization to yield the third argument if COND is false
template<bool COND, typename TrueType, typename FalseType>
struct IfThenElseT{
  using Type = TrueType;
};

template<typename TrueType, typename FalseType>
struct IfThenElseT<false, TrueType, FalseType>{
  using Type = FalseType;
};

template<bool COND, typename TrueType, typename FalseType>
using IfThenElse = typename IfThenElseT<COND, TrueType, FalseType>::Type;

#endif // IFTHENELSE_HPP
