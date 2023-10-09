#include <type_traits> //defines true_type and false_type
#include "removereference.hpp"

// Helper to ignore any number of template parameters
template<typename...> using VoidT = void;

// Primary template
template<typename, typename = VoidT<>>
struct HasSizeTypeT : std::false_type {
};

// Partial specialization (may be SFINAE'd away)
template<typename T>
struct HasSizeTypeT<T, VoidT<typename T::size_type>> : std::true_type{
};

/* Below version that attempts remove references returns false for non reference types, ie. it does not work. Not sure why, yet it is from the book
struct HasSizeTypeT<T, VoidT<typename RemoveReferenceT<T>::size_type>> : std::true_type{
}; 

*/
