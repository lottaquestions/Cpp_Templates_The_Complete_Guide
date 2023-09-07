#include <cstddef>

// To compile: g++ -std=c++17 decay.hpp decay.cpp -o decay.bin

// Primary template declaration
template<typename T>
struct DecayT {
    using Type = T;
};

template<typename T>
struct DecayT<T[]>{
  using Type = T*;
};

template<typename T, std::size_t N>
struct DecayT<T[N]>{
  using Type = T*;
};

template<typename R, typename... Args>
struct DecayT<R(Args...)>{
  using Type = R(*)(Args...);
};

// Partial specialization matches any function type that uses C-style varargs
template<typename R, typename...Args>
struct DecayT<R(Args...,...)>{
  using Type = R(*)(Args...,...);
};
