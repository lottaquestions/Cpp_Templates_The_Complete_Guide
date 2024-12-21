#include "ratioadd.hpp"

// Duration type for values of type T with unit type U
template<typename T, typename U = Ratio<1>>
class Duration{
    public:
    using ValueType = T;
    using UnitType = typename U::Type;
    private:
    ValueType val;

    public:
    constexpr Duration(ValueType v = 0) : val(v){}
    constexpr ValueType value(){
        return val;
    }

};

// Adding two durations where unit type might differ
template<typename T1, typename U1, typename T2, typename U2>
auto constexpr operator+(Duration<T1,U1> const& lhs, Duration<T2,U2> const& rhs){
    // Resulting type is a unit with a 1 numerator and the resulting denominator
    // of adding both unit type fractions 
    using VT = Ratio<1, RatioAdd<U1,U2>::den>;

    // Resulting value is the sum of both values converted to the resulting unit type
    auto val = lhs.value() * VT::den / U1::den * U1::num + rhs.value() * VT::den / U2::den * U2::num;
    return Duration<decltype(val), VT>(val);
}

/*
We allow the arguments to have different unit types, U1 and U2. And we use these unit types to compute 
the resulting duration to have a unit type that is the corresponding unit fraction 
(a fraction where the numerator is 1). With all that in place, we can compile the following code:


int x = 42;
int y = 77;

auto a = Duration<int, Ratio<1,1000>>(x);     // x milliseconds
auto b = Duration<int, Ratio<2,3>>(y);        // y 2/3 seconds
auto c = a + b; //computes resulting unit type 1/3000 seconds
                //and generates run-time code for c = a*3 + b*2000
*/