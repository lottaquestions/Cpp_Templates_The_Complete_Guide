#include <type_traits> // for true_type and false_type
#include <utility> // for declval
#include <concepts>

template <typename From, typename To>
constexpr bool is_convertible_v =
  (std::is_void_v<From> and std::is_void_v<To>)
  or requires { { std::declval<To(&)(To)>()(std::declval<From>()) }; };

template <typename From, typename To>
struct is_convertible : std::bool_constant<is_convertible_v<From, To>> {};
