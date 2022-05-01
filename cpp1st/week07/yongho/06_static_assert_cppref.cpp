//cppreference example
#include <iostream>
#include <type_traits>

static_assert(03301 == 1729); //since C++17 the message string is optional

template <class T>
void swap(T& a, T& b) noexcept
{
    static_assert(std::is_copy_constructible_v<T>, "Swap requires copying");
    static_assert(std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_copy_assignable_v<T>, "Swap requires nothrow copy/assign");
    auto temp=b;
    b = a;
    a = temp;
}

template <class T>
struct data_structure
{
    static_assert(std::is_default_constructible_v<T>, "Data structure requires default-constructable elements");
};

struct no_copy
{
    no_copy (const no_copy&) = delete;
    no_copy () = default;
};

struct no_default
{
    no_default () = delete;
};

int main()
{
    //int a =1 , b = 2;
    int a, b;
    //std::cout << "a = " << a << ", b=" << b << std::endl;
    swap(a, b);
    //std::cout << "After Swap" << std::endl;
    //std::cout << "a = " << a << ", b=" << b << std::endl;

    no_copy nc_a, nc_b;
    swap(nc_a, nc_b);   //"copy constructor" was deleted in 'no_copy' struct, so 'is_copy_constructible' return false.
                        //"delete move constructor" and "move assignment operator" was not implicitly created, 
                        //so 'is_nothrow_move_constructible' and 'is_nothrow_move_assignable' are resturn false.

    [[maybe_unused]] data_structure<int> ds_ok;
    [[maybe_unused]] data_structure<no_default> ds_error; //"default constructor" was deleted in 'no_default' struct, so 'is_default_constructible' return false.
}