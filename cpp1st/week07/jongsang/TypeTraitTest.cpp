
#include "TypeTraitTest.h"
#include <iostream>
#include <boost/type_index.hpp>

void TypeTraitTest::testTypeTraitCategory()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    // C++ 17
    auto same_type = std::is_same_v<uint8_t, char>;
    std::cout << "same_type : " << same_type << std::endl;
    // before C++ 17
    auto old_same_type = std::is_same<uint8_t, char>::value;
    std::cout << "same_type : " << old_same_type << std::endl;

    // C++ 17
    auto flt = 0.3f;
    auto is_float_or_double = std::is_floating_point_v<decltype(flt)>;
    std::cout << "is_float_or_double : " << is_float_or_double << std::endl;
    // before C++ 17
    auto old_is_float_or_double = std::is_floating_point<decltype(flt)>::value;
    std::cout << "is_float_or_double : " << old_is_float_or_double << std::endl;

    class Parent {};
    class Child : public Parent {};
    class Infant {};
    //static_assert(std::is_base_of_v<Child, Parent>, "Problem");
    static_assert(!std::is_base_of_v<Infant, Parent>, "");

}

// /////////////////////////////////////////////////////////////////////
template <typename T>
decltype(auto) TypeTraitTest::sign_func(const T& v)
{
    if (std::is_unsigned_v<T>)
    {
        return 1;
    }
    return v < 0 ? -1 : 1;
}

void TypeTraitTest::testTypeTraits()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    auto unsigned_v = uint32_t{ 32 };
    std::cout << "uint32_t : sing_func -> " << sign_func(unsigned_v) << std::endl;;

    auto signed_d = int32_t{ 32 };
    std::cout << "int32_t : sing_func -> " << sign_func(signed_d) << std::endl;;

}

// /////////////////////////////////////////////////////////////////////
void TypeTraitTest::testLambdaWithAuto()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    using boost::typeindex::type_id_with_cvr;

    auto sign_func = [](const auto& v) -> int {
        // check type of v
        std::cout << "v type : " << type_id_with_cvr<decltype(v)>().pretty_name() << std::endl;
        // check decltype(v)
        using ReferenceType = decltype(v);
        std::cout << "ReferenceType : " << type_id_with_cvr<ReferenceType>().pretty_name() << std::endl;
        // check remove_reference_t of decltype(v)
        using ValueType = std::remove_reference_t<ReferenceType>;
        std::cout << "ValueType : " << type_id_with_cvr<ValueType>().pretty_name() << std::endl;
        // check remove_cv_t of ValueType
        using ValueType2 = std::remove_cv_t<ValueType>;
        std::cout << "ValueType2 : " << type_id_with_cvr<ValueType2>().pretty_name() << std::endl;
        if (std::is_unsigned_v<ValueType>)
        {
            return 1;
        }
        return v < 0 ? -1 : 1;
    };

    auto unsigned_v = uint32_t{ 32 };
    std::cout << "uint32_t : sing_func -> \n" << sign_func(unsigned_v) << std::endl;;

    auto signed_d = int32_t{ -1 };
    std::cout << "int32_t : sing_func -> \n" << sign_func(signed_d) << std::endl;;
}

// Reference : C++ High Performance
