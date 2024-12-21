#include <iostream>
#include <array>

// To compile: g++ -std=c++17 -O0 -g3 rank.cpp -o rank.bin

// Primary template handles scalar (non-array) types
template<typename T>
struct rank{
    static constexpr int value = 0u; 
};

// Partial specialization recognizes any array type
template<typename T, size_t N>
struct rank<T[N]>
{
    static constexpr int value = 1u + rank<T>::value;
};


int main(){
    using array_t = int[10][20][30];
    using array_t1 = int[10];
    std::cout <<  "Rank of the array_t is " << rank<array_t>::value << std::endl;
    std::cout <<  "Rank of the array_t1 is " << rank<array_t1>::value << std::endl;
    return 0;
}

