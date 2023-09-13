//Result Type Traits

/*
 * This trait template uses decltype to compute the type of the expression T1() + T2(), 
 * leaving the hard work of determining the result type (including handling promotion rules 
 * and overloaded operators) to the compiler.
*/

template<typename T1, typename T2>
struct PlusResultT{
  using Type = decltype(T1() + T2()); // Note for this to work, T1 and T2 must have an accessible, nondeleted, default constructor (or be nonclass types)
};

template<typename T1, typename T2>
using PlusResult = typename PlusResultT<T1,T2>::Type;


/* The above result type trait can be used, for example in a function template that adds two arrays
   as shown below. The two arrays can be of different type e.g. int and char. Note how the hard work
   of determining the return value has been left to the compiler by using decltype.
*/

template <typename T>
struct Array{};

template<typename T1, typename T2>
Array<PlusResult<T1,T2>>
operator+(Array<T1> const&, Array<T2> const&);

/* Because of the way the result trait has been defined, it preserves too much information of the return type
 * i.e. it is too specific, which could cause issues if we pass it on to another function that does not expect 
 * the extra information, which could be reference or constant information.
 * This can be fixed by nesting the result type trait in other type traits that strip out the extra information
*/
#include "removecv.hpp"
#include "removereference.hpp"

template<typename T1, typename T2>
Array<RemoveCV<RemoveReference<PlusResult<T1,T2>>>>
operator+(Array<T1> const&, Array<T2> const&);
