#include "hasplus.hpp"

template<typename T1, typename T2, bool = HasPlusT<T1,T2>::value>
struct PlusResultT{ // primary template used when HasPlusT yields true
  using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
struct PlusResultT<T1, T2, false>{ // partial specialization used otherwise
};


/********************************
 *  Example usage of PlusResultT
 ********************************
 */

class A{};
class B{};

template<typename T>
class Array{
  T value[];
};

// Declare generic + for arrays of different types;
template<typename T1, typename T2>
Array<typename PlusResultT<T1, T2>::Type> operator+(Array<T1> const&, Array<T2> const&);

// Overload + for concrete types
Array<A> operator+(Array<A> const& arrayA, Array<B> const& arrayB);

// Due to SFINAE, the instantiation of PlusResultT<A,B> will not have a Type member, because A and B values are not addable.
// Therefore, the result type of the array operator+ template is invalid (the generic + above), and SFINAE will eliminate
// the function template from consideration. The overloaded operator+ that is specific to Array<A> and Array<B> will therefore be chosen.
// The primary template of HasPlusT is chosen since `decltype(std::declval<T1>() + std::declval<T2>())` is invalid for our case.
// The primary template of HasPlustT generates an instantiation that is a false_type. This causes the specialization of PlusResultT
// i.e `struct PlusResultT<T1, T2, false>` to be chosen. But this specialization does not have a Type member so
// `Array<typename PlusResultT<T1, T2>::Type> operator+(Array<T1> const&, Array<T2> const&);` cannot be chosen and instead the concrete
// overload `Array<A> operator+(Array<A> const& arrayA, Array<B> const& arrayB);` is chosen.

void AddAB(Array<A> const& arrayA, Array<B> const& arrayB){
  auto sum = arrayA + arrayB; // See above comment for why this works
}
