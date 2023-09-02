template<typename T>
struct RemoveVolatileT{
  using Type = T;
};

template<typename T>
struct RemoveVolatileT<T volatile>{
  using Type = T;
};

template<typename T>
using RemoveVolatile = typename RemoveVolatileT<T>::Type;

/*
 * There are two things to note with the definition of RemoveCVT. First, it is making use of both RemoveConstT and the related RemoveVolatileT, first removing the volatile (if present) 
 * and then passing the resulting type to RemoveConstT. Second, it is using metafunction forwarding to inherit the Type member from RemoveConstT rather than declaring its own Type member
 * that is identical to the one in the RemoveConstT specialization. Here, metafunction forwarding is used simply to reduce the amount of typing in the definition of RemoveCVT. However, 
 * metafunction forwarding is also useful when the metafunction is not defined for all inputs.
 */
