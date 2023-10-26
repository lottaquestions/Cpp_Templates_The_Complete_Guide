#include <type_traits> // for true_type and false_type
#include <utility> // for declval
#include <concepts>

// handle void being convertible to void
template <typename From, typename To>
struct is_convertible : std::conjunction<std::is_void<From>, std::is_void<To>> {};

// handle everything else
template <typename From, typename To>
  requires requires {
    { std::declval<To(&)(To)>()(std::declval<From>()) };
  }
struct is_convertible<From, To> : std::true_type {};
