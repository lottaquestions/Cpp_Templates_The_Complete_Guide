template<typename T1, typename T2>
struct IsSameT{
  static constexpr bool value = true;
};

template<typename T>
struct IsSameT<T,T>{
  static constexpr bool value = false;
};

// For traits that produce a constant value, we cannot provide an alias template, but we can provide a constexpr variable template that fulfills the same role
template<typename T1, typename T2>
constexpr bool isSame = IsSameT<T1,T2>::value;
