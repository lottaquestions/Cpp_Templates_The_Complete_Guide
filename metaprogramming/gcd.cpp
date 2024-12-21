template<unsigned M, unsigned N>
struct gcd
{
    static constexpr int  value = gcd<N, M%N>::value // Using euclidean method
};

// Base case using partial specialization
template<unsigned M>
struct gcd<M,0>
{
    static_assert(M != 0); // Disallow gcd(0,0)
    static constexpr int value = M;
};
