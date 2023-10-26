#include <utility> // For declval
#include <type_traits> // For true_type, false_type and void_t

// Primary template
template<typename, typename = std::void_t<>>
struct HasBeginT : std::false_type {};

// Partial specialization (may be SNIFAE'd away)
template<typename T>
struct HasBeginT<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type{};
