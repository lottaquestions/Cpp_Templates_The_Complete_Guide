template<unsigned N, unsigned D = 1>
struct Ratio{
    static constexpr unsigned num = N; // Numerator
    static constexpr unsigned den = D; // Denominator
    using Type = Ratio<nu,den>;
};
