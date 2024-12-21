#include "ratio.hpp"
template<typename R1, typename R2>
struct RatioAddImpl{
    private:
    static constexpr unsigned den = R1::den * R2::den;
    static constexpr unsigned num = R1::num * R2::den + R2::num*R1::den;

    public:
    typedef Ratio<num,den> Type;
};

// Using declaration for convenient usage
template<typename R1, typename R2>
using RatioAdd = RatioAddImpl<R1,R2>::Type;

/*
This allows us to compute the sum of two ratios at compile time:

using R1 = Ratio<1,1000>;
using R2 = Ratio<2,3>;
using RS = RatioAdd<R1,R2>;                     //RS has type Ratio<2003,2000>
std::cout << RS::num << ’/’ << RS::den << ’\n’; //prints 2003/3000

using RA = RatioAdd<Ratio<2,3>,Ratio<5,7>>;     //RA has type Ratio<29,21>
std::cout << RA::num << ’/’ << RA::den << ’\n’; //prints 29/21
*/