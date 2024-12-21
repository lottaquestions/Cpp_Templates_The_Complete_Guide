template<typename... Elements>
class TypeList{};


// Example usage:
using SignedIntegralTypes = Typelist<signed char, short, int, long, long long>;


// Front metafunction extracts the first element from the typelist:
template<typename List>
class FrontT;

template<typename Head, typename... Tail>
class FrontT<TypeList<Head, Tail...>>{
    public:
    using Type = Head;
};

template<typename List>
using Front = typename FrontT<List>::Type;

// PopFront metafunction removes the first element from the typelist
template<typename List>
class PopFrontT;

template<typename Head, typename... Tail>
class PopFrontT<TypeList<Head, Tail...>>{
    public:
    using Type = TypeList<Tail...>;
};

template<typename List>
using PopFront = typename PopFrontT<List>::Type;

/*
PopFront<SignedIntegralTypes> produces the typelist

Typelist<short, int, long, long long>
*/

template<typename List, typename NewElement>
class PushFrontT;

template<typename... Elements, typename NewElement>
class PushFrontT<TypeList<Elements...>, NewElement>{
    public:
    using Type = TypeList<NewElement, Elements...>;
};

template<typename List, typename NewElement>
using PushFront = PushFrontT<List, NewElement>::Type;