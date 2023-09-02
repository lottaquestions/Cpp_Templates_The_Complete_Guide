#include <vector>
#include <list>

template<typename T>
struct ElementT; // Primary template

template<typename T>
struct ElementT<std::vector<T>>{ // partial specialization of std::vector
  using Type = T;
};

template<typename T>
struct ElementT<std::list<T>> { // partial specialization of std::list
  using Type = T;
};

template<typename T, std::size_t N>
struct ElementT<T[N]>{ // parial specialization of array of known bounds
  using Type = T;
};

template <typename T>
struct ElementT<T[]>{ // partial specialization of arrays of unknown bounds
  using Type = T;
};
