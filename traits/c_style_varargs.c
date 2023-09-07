#include <stdio.h>
#include <stdarg.h>

// A simple varargs function that calculates the sum of integers.
int sum(int num, ...) {
    int result = 0;

    va_list args;  // Declare a va_list to hold the variable arguments.
    va_start(args, num);  // Initialize the va_list with the variable arguments.

    for (int i = 0; i < num; i++) {
        // Use va_arg to access each argument, and specify its type.
        int value = va_arg(args, int);
        result += value;
    }

    va_end(args);  // Cleanup the va_list.

    return result;
}

int main() {
    int s1 = sum(3, 10, 20, 30);
    int s2 = sum(4, 5, 10, 15, 20);

    printf("Sum 1: %d\n", s1);
    printf("Sum 2: %d\n", s2);

    return 0;
}
