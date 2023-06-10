#pragma once
#include <memory>

template <typename T, std::size_t Size, std::size_t Allignment>
class FastPimpl
{
public:
    template <typename... Args>
    explicit FastPimpl(Args &&...args)
    {
        new (&buffer) T(std::forward<Args>(args)...);
    }
    ~FastPimpl()
    {
        validate<sizeof(T), alignof(T)>();
        operator->()->~T();
    }
    FastPimpl(FastPimpl const &other)
    {
        new (&buffer) T(*other);
    }
    FastPimpl(FastPimpl &&other)
    {
        new (&buffer) T(std::move(*other));
    }
    FastPimpl& operator=(const FastPimpl& other)
    {
        operator*() = *other;
        return *this;
    }
    FastPimpl& operator=(FastPimpl &&other)
    {
        operator*() = std::move(*other);
        return *this;
    }
    T& operator*()
    {
        return *reinterpret_cast<T*>(&buffer);
    }
    T* operator->()
    {
        return &operator*();
    }
private:
    template <std::size_t ActualSize, std::size_t ActualAllignment>
    void validate()
    {
        static_assert(Size == ActualSize, "Size and sizeof(T) aren't equal");
        static_assert(Allignment == ActualAllignment, "Allignment and alignof(T) aren't equal");
    }
    typename std::aligned_storage<Size, Allignment>::type buffer;
};