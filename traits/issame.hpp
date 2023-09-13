#include "boolconstant.hpp"

template <typename T1, typename T2>
struct IsSameT : FalseType{};

template<typename T>
struct IsSameT<T,T> : TrueType{};

/*
   The resulting type of

      IsSameT<T,int>

   implicitly converts to its base class TrueType or FalseType, which not only provides the corresponding value member but also allows us to dispatch to different function implementations or partial class template specializations at compile time
*/
