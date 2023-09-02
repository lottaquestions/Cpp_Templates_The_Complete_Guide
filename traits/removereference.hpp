template<typename T>
struct RemoveReferenceT{
  using Type = T;
};

template<typename T>
struct RemoveReferenceT<T&>{
  using Type = T;
};

template<typename T>
struct RemoveReferenceT<T&&>{
  using Type = T;
};

// A convenience alias
template<typename T>
using RemoveReference = typename RemoveReferenceT<T>::Type;
