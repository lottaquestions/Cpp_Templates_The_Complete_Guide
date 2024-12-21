#include <type_traits>

/// Example 1
// Primary template
template<typename, typename = void> // default second argument is essential for primary, for the technique to work
struct has_type_member : false_type { };

// Partial specialization
template<typename T>
struct has_type_member<T, void_t<typename T::type>> : true_type { }; // For well formed cases with ::type, this will be chosen

// Note that both the primary and specialization use void. This works because of the reliance on the type T having to be
// well-formed. If is is not well formed, then SFINAE selects the primary. The more specialized template overload is chosen
// for well formed parameters. Note: More specialized templates are chosen first over general ones. 


/// Example 2
// Helper alias for the result type of a valid copy assignment
template<typename T>
using copy_assignment_t = decltype(declval<T&>() = declval<T const&>() ); // Return value of a copy assignment. This is the signature
// of a copy assignment

// Primary template handles all non-copy-assignable types
template<typename T, typename = void> // Default argument is essential
struct is_copy_assignable : false_type { };

// Specialization recognizes and validates only copy-assignable types
template<typename T>
struct is_copy_assignable<T, void_t<copy_assignment_t<T>>> // Second param works only for well formed types
: is_same<copy_assignment_t<T>, T&>{ }; // The inheritance checks that the return type of copy assignment is the expected one. If it fails,
// then this partial specialization will inherit from false_type which will give a result of false for the trait, i.e. not copy assignable


/// Example 3
// Move assignment checker
template<typename T>
using move_assignment_t = decltype(declval<T&&>() = declval<T const&>() ); // Return value of a move assignment. This is the signature
// of a move assignment

// Primary template handles all non-move-assignable types
template<typename T, typename = void> // Default argument is essential
struct is_move_assignable : std::false_type { };

// Specialization recognizes and validates only copy-assignable types
template<typename T>
struct is_move_assignable<T, void_t<move_assignment_t<T>>> // Second param works only for well formed types
: is_same<move_assignment_t<T>, T&&>{ }; 

template<typename T>
struct type_identity{
    using type = T;
};

/// Example 4 
template<typename T, typename = void>
struct add_lvalue_reference : type_identity<T> { };

template<typename T, void_t<T &>> // Check if T & is well formed
struct add_lvalue_reference : type_identity<T &> { }; // Add lvalue reference using identity function as a vehicle


