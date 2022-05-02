//When we need function is changed depends on Type.
//If type is pointer, it returns value to which it can point.
//If type is not pointer, it returns original value.

//If a 'constexpr if' statement appears inside a templated entity, and if condition is not value-dependent after instantiation, 
//the discarded statement is not instantiated when the enclosing template is instantiated .

#include <iostream>
#include <type_traits>

template <typename T>
constexpr T show_value(T t)
{
    //template가 인스턴스와 되면서 생성되는 코드에 컴파일 불가능한 부분이 발생함. *t가 실행되지 않음에도 컴파일이 되지 않음.
    //if constexpr is true, else statement is ignored(not compiled)
    //if constexpr is false, else statement is compiled.
    //if (std::is_pointer<T>::value) 
    if constexpr (std::is_pointer<T>::value)
    {
        // std::cout << "Is a pointer: " << *t << std::endl;
        return t;
    }
    else
    {
        // std::cout << "Is Not a pointer: " << t << std::endl;
        return t*2;
    }
}

int main()
{
    constexpr int x=3;
    constexpr auto result = show_value(x); //Build error when constexpr is not used.
    static_assert(result == 6);

    constexpr int y=7;
    constexpr const int* const p = 0;
    constexpr auto result2 = show_value(p);
    static_assert(result2 == p);
}