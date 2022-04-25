#include "TemplateDeduction.h"

void TemplateDeduction::testTypeDeduction0()
{
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;

    std::cout << "===== int x =====" << std::endl;
    refT_func(x);
    std::cout << "===== int& rx = x =====" << std::endl;
    refT_func(rx);
    std::cout << "===== const int cx = x =====" << std::endl;
    refT_func(cx);
    std::cout << "===== const int& crx = x =====" << std::endl;
    refT_func(crx);
}

void TemplateDeduction::testTypeDeduction1()
{
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;

    std::cout << "===== int x =====" << std::endl;
    uRefT_func(x);
    std::cout << "===== int& rx = x =====" << std::endl;
    uRefT_func(rx);
    std::cout << "===== const int cx = x =====" << std::endl;
    uRefT_func(cx);
    std::cout << "===== const int& crx = x =====" << std::endl;
    uRefT_func(crx);
    std::cout << "===== 100 =====" << std::endl;
    uRefT_func(100);
}

void TemplateDeduction::testTypeDeduction2()
{
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;
    const char* const ptr = "Hello world";

    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;

    std::cout << "===== int x =====" << std::endl;
    func(x);
    std::cout << "===== int& rx = x =====" << std::endl;
    func(rx);
    std::cout << "===== const int cx = x =====" << std::endl;
    func(cx);
    std::cout << "===== const int& crx = x =====" << std::endl;
    func(crx);
    std::cout << "===== const char* const ptr =====" << std::endl;
    func(ptr);
}
