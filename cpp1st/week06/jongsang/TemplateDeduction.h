#pragma once
#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>

class TemplateDeduction
{
public:
    template <typename T>
    void refT_func(T& param)
    {
        using boost::typeindex::type_id_with_cvr;
        std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n"
            << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n" 
            << std::endl;
    }

    template <typename T>
    void uRefT_func(T&& param)
    {
        using boost::typeindex::type_id_with_cvr;
        std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n"
            << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n" 
            << std::endl;
    }

    template <typename T>
    void func(T param)
    {
        using boost::typeindex::type_id_with_cvr;
        std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n"
            << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n" 
            << std::endl;
    }
    void testTypeDeduction0();
    void testTypeDeduction1();
    void testTypeDeduction2();
};

