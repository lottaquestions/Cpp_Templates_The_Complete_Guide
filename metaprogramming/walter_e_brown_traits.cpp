#include <type_traits>
namespace walter{

    // Primary template for non-void types
    template<typename T> 
    struct is_void : std::false_type
    {
    };
    // Specializations for void types
    template<typename T>
    struct is_void<void> : std::true_type
    {
    };
    template<typename T>
    struct is_void<void const> : std::true_type
    {
    };

    // Primary template for different types
    template<typename T, typename U>
    struct is_same : std::false_type
    {
    };

    // Specialization for non same types
    template<typename T>
    struct is_same<T, T> : std::true_type
    {
    };
    
    
    
    
}