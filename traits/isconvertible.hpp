#include <type_traits> // for true_type and false_type
#include <utility> // for declval

/* NOTE: This example does not compile on C++17. Not sure why*/
template<typename FROM, typename TO>
struct IsConvertibleHelper{
private:
  // test () trying to call the helper aux(TO) for a FROM passed as F
  static void aux(TO);

  // This SFINAE works by using an unnamed template parameter that is not publicly available. Since a user does not supply the third template
  // parameter, the compiler tries to substitute it and if the substitution fails, then the template choice is discarded.
  // Context (scope) specific template parameters F and T are introduced to make the SFINAE work. Otherwise if FROM and TO were used,
  // it would be a compilation error.
  template<typename F, typename, typename = decltype(aux(std::declval<F>()))> 
  static std::true_type test(void*);

  // test() fallback
  template<typename, typename>
  static std::false_type test (...);

public:
  using Type = decltype(test<FROM>(nullptr));
};

template<typename FROM, typename TO>
struct IsConvertibleT : IsConvertibleHelper<FROM,TO>::Type{};

template<typename FROM, typename TO>
using IsConvertible = typename IsConvertibleT<FROM,TO>::Type;

template<typename FROM, typename TO>
constexpr bool isConvertible = IsConvertibleT<FROM,TO>::value;
