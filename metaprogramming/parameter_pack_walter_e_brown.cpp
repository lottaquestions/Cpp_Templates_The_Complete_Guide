#include <type_traits>

// Below is for finding if a single type is a part of a list of types

namespace walter{
// Primary template: T is the same as any of the P0toN types
template<typename T, typename... P0toN>
struct is_one_of;

// Base #1 : specialization recognizes empty list of types
template<typename T>
struct is_one_of : false_type { };

// Base #2 : specialization recognizes match at head of the list
template<typename T, typename... P0toN>
struct is_one_of<T, T, P0toN...> : true_type { };

// Specialization recognizes mismatch at head of the list
template<typename T, typename P0, typename... P0toN>
struct is_one_of<T, P0, P0toN...> : is_one_of<T, P0toN...> { }; // Notice the recursion is via inheritance

//Example usage
template<typenam T>
using is_void = is_one_of<T, void, void const, void volatile, void const volatile>;

}

