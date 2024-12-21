#include <cstddef>

template<typename T>
struct RemoveAllExtentsT{
    using Type = T;
};

// Partial specializations for array types (with and without bounds)
template<typename T, std::size_t SZ>
struct RemoveAllExtentsT<T[SZ]>{
    using Type = typename RemoveAllExtentsT<T>::Type;
};

template<typename T>
struct RemoveAllExtentsT<T[]>{
    using Type = typename RemoveAllExtentsT<T>::Type;
};

template<typename T>
using RemoveAllExtents = typename RemoveAllExtentsT<T>::Type;

/*
Here, RemoveAllExtents is a type metafunction (i.e., a computational device that produces a result type) 
that will remove an arbitrary number of top-level “array layers” from a type.2 You can use it as follows:

RemoveAllExtents<int[]>        // yields int
RemoveAllExtents<int[5][10]>   // yields int
RemoveAllExtents<int[][10]>    // yields int
RemoveAllExtents<int(*)[5]>    // yields int(*)[5]

The metafunction performs its task by having the partial specialization that matches the top-level array case 
recursively “invoke” the metafunction itself.

*/