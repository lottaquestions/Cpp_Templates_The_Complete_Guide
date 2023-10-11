#include <utility> // For declval
#include <type_traits> // For true_type, false_type and void_t

// To compile: g++ -std=c++17 -c hasvarious.hpp

// Primary template
template<typename, typename = std::void_t<>>
struct HasVariousT : std::false_type{};

// Partial specialization (may be SFINAE'd away)
template<typename T>
struct HasVariousT<T, std::void_t<decltype(std::declval<T>().begin()), typename T::difference_type, typename T::iterator>> : std::true_type{};
