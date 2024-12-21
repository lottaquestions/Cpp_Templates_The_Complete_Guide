#include <iostream>
#include <type_traits>

// Primary template handles scalar types
template<typename T>
struct rank : std::integral_constant<size_t, 0u>
{};

// Partial specialization recognizes bounded array types
template<typename T, size_t N>
struct rank<T[N]> : std::integral_constant<size_t, 1u + rank<T>::value>
{
};

// Partial specialization recognizes unbounded array types
template<typename T>
struct rank<T[]> : std::integral_constant<size_t, 1u + rank<T>::value>
{
};

int main(){
    using array_t = int[10][20][30];
    using array_t1 = int[10];
    std::cout <<  "Rank of the array_t is " << rank<array_t>::value << std::endl;
    std::cout <<  "Rank of the array_t1 is " << rank<array_t1>::value << std::endl;
    return 0;
}