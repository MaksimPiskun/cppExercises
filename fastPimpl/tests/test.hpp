#include <FastPimpl.hpp>

struct Impl;

class TestClass
{
    static constexpr std::size_t size = 4;
    static constexpr std::size_t allignment = 4;
    FastPimpl<Impl, size, allignment> pimpl;

public:
    TestClass() = default;
    ~TestClass() = default;
    void Set(int num);
    int Get();
};
