#include <type_traits>
// The operands of sizeof, typeid, decltype, and noexcept are never evaluated, not even at compile time:
// - Implies that no code is generated (in these contexts) for such operand expressions
// - Implies that we need only a declaration, not a definition, to use a (functions's or object's) name in these contexts.

// An unevaluated function call can usefully map one type to another:  

//          decltype(foo(declval<T>()));
	  	    //Gives foo's return type were it called with a T rvalue
	  
// The unevaluated call `declval<T>()` is declared to give an rvalue of type T. `declval<T&>()` gives an lvalue.  

// An example that uses the above technique is shown below:
namespace walter{
template<typename T>
struct is_copy_assignable
{
    private:

    template<typename U, typename = decltype(declval<U&>() = declval<U const&>())> // second param is unused hence not named even though it has a sdefault value
    static true_type try_assignment(U&&); // SFINAE will select this one if unamed template matches

    static false_type try_assignment(...); // Catch-all overload. No template parameters required.

    public:
    using type = decltype(try_assignment(declval<T>() ) );
};

}
