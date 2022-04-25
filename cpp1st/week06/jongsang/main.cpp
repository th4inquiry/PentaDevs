// main.cpp : Type deduction example source code
//

#include "Person.h"
#include "AutoDeduction.h"
#include "TemplateDeduction.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

void testBasicRef()
{
    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;

    int x = 10;
    int z = 100;
    int& rx = x;
    int const& crx = x;
    rx = z;

    int* px = &x;
    int* pz = &z;
    int*& rpx = px;
    int* const& crpx = px;

    std::cout << "============" << std::endl;
    std::cout << "px address : " << std::addressof(px) << " || value : " << px << "\n";
    std::cout << "crpx address : " << std::addressof(crpx) << " || value : " << crpx << "\n" << std::endl;

    int y = 20;
    px = &y;
    rpx = pz;

    std::cout << "============" << std::endl;
    std::cout << "px address : " << std::addressof(px) << " || value : " << px << "\n";
    std::cout << "crpx address : " << std::addressof(crpx) << " || value : " << crpx << "\n" << std::endl;
}
int main()
{
    testBasicRef();

    TemplateDeduction templateDeduction;
    templateDeduction.testTypeDeduction0();
    templateDeduction.testTypeDeduction1();
    templateDeduction.testTypeDeduction2();

    AutoDeduction autoDeduction;
    autoDeduction.testTypeDeduction0();
    autoDeduction.testTypeDeduction1();
    autoDeduction.testTypeDeduction2();
    autoDeduction.testTypeDeduction3();

}
