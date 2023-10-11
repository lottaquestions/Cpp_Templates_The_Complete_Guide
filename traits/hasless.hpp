#include <utility> // For declval
#include <type_traits> // For true_type, false_type and void_t

// Primary template
template<typename, typename, typename = std::void_t<>>
struct HasLessT : std::false_type{};

// Partial specialization (may be SFINAE'd away)
template<typename T1, typename T2>
struct HasLessT<T1, T2, std::void_t<decltype(std::declval<T1>() < std::declval<T2>())>> : std::true_type{};
