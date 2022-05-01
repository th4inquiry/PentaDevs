//When we need function is changed depends on Type.
//If type is pointer, it returns value to which it can point.
//If type is not pointer, it returns original value.

#include <iostream>
#include <type_traits>

template <typename T>
void show_value(T t)
{
    //template가 인스턴스와 되면서 생성되는 코드에 컴파일 불가능한 부분이 발생함. *t가 실행되지 않음에도 컴파일이 되지 않음.
    //if constexpr is true, else statement is ignored(not compiled)
    //if constexpr is false, else statement is compiled.
    if (std::is_pointer<T>::value) 
    //if constexpr (std::is_pointer<T>::value)
    {
        std::cout << "Is a pointer: " << *t << std::endl;
    }
    else
    {
        std::cout << "Is Not a pointer: " << t << std::endl;
    }
}

// template <typename T>
// void show_value(T* t)
// {
//     std::cout << "Is a pointer: " << *t << std::endl;
// }

int main()
{
    int x=3;
    show_value(x); //Build error when constexpr is not used.

    int y=7;
    int* p = &y;
    show_value(p);

}