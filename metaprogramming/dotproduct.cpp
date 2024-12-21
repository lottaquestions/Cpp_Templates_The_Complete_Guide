#include <cstddef>

// Hybrid metaprogramming

template<typename T, std::size_t N>
struct DotProductT{
    static inline T result(T* a, T* b){
        return *a * *b + DotProductT<T,N-1>::result(a+1, b+1);
    }
};

// Partial specialization as end criteria
template<typename T>
struct DotProductT<T,0>{
    static inline T result(T*, T*){
        return T{};
    }
};

template<typename T, std::size_t N>
auto dotProduct(std::array<T,N> const& x, std::array<T,N> const& y){
    return DotProductT<T,N>::result(x.begin(), y.begin());
}
