#include "issame.hpp"
#include <type_traits> // defines true_type and false_type

// Helper to ignore any number of template parameters
template<typename...> using VoidT = void;

// Primary template
template<typename, typename = VoidT<>>
struct IsDefaultConstructibleT : std::false_type{
};

// Partial specialization, may be SFINAE'd away
template<typename T>
struct IsDefaultConstructibleT<T, VoidT<decltype(T())>>::std::true_type{
};
