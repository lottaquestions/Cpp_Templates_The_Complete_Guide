#include <iostream>

// Base case: The sum of no numbers is 0.
int sum() {
    return 0;
}

// Recursive variadic template function to calculate the sum of integers.
template <typename T, typename... Args>
int sum(T first, Args... rest) {
    return first + sum(rest...);
}

int main() {
    int s1 = sum(10, 20, 30);
    int s2 = sum(5, 10, 15, 20);

    std::cout << "Sum 1: " << s1 << std::endl;
    std::cout << "Sum 2: " << s2 << std::endl;

    return 0;
}
