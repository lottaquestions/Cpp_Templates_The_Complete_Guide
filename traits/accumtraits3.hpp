template<typename T>
struct AccumulationTraits;

template<>
struct AccumulationTraits<char>{
  using AccT = int;  // Type trait
  constexpr static AccT zero = 0; // Value trait
};

template<>
struct AccumulationTraits<short>{
  using AccT = int;
  constexpr static AccT zero = 0;
};

template<>
struct AccumulationTraits<int>{
  using AccT = long;
  constexpr static AccT zero = 0;
};

template<>
struct AccumulationTraits<unsigned int>{
  using AccT = unsigned long;
  constexpr static AccT zero = 0;
};

template<>
struct AccumulationTraits<float>{
  using AccT = double;
  constexpr static AccT zero = 0;
};

/* Note, the above value trait techniques only work for primitive types.
 * For user defined types we have to declare the value trait as inline
 * to allow it to be created during compile time.
 */
struct BigInt{
  BigInt(long long initVal){x = initVal;}
  long long x;
};

template<>
struct AccumulationTraits<BigInt>{
  using AccT = BigInt;
  inline static BigInt const zero  = BigInt{0}; // Works since C++17. Unfortunately cannot use constexpr
};
