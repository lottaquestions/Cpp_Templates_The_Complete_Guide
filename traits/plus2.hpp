#include <utility>

template<typename T1, typename T2>
struct PlusResultT{
  using Type = decltype(std::declval<T1>() + std::declval<T2>()); // declval eliminates the need for value initialization of T1 and T2 when determining the result type
};

template<typename T1, typename T2>
using PlusResult = typename PlusResultT<T1,T2>::Type;
