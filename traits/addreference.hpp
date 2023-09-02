template <typename T>
struct AddLValueRerenceT{
  using Type = T&;
};

template<>
struct AddLValueReferenceT<void> {
  using Type = void;
};

template<>
struct AddLValueReferenceT<void const> {
  using Type = void const;
};

template<>
struct AddLValueReferenceT<void volatile> {
  using Type = void volatile;
};

template<>
struct AddLValueReferenceT<void const volatile> {
  using Type = void const volatile;
};

// Convenience alias
template<typename T>
using AddLValueRerence = typename AddLValueRerenceT<T>::Type;

template<typename T>
struct AddRValueRerenceT{
  using Type = T&&;
};

// Convenience alias
template<typename T>
using AddRValueRerence = typename AddRValueRerenceT<T>::Type;

/*
 * The rules of reference collapsing (Section 15.6 on page 277) apply here. For example, 
 * calling AddLValueReference<int&&> produces type int& (there is therefore no need to 
 * implement them manually via partial specialization)
 */
