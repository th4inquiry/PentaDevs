// lambda tempalte

#include <iostream>

using namespace std;

auto sumTemplate = []<typename T>(T num1, T num2) { return num1 + num2; };

int main()
{
    int i = sumTemplate(2, 3);
    float f = sumTemplate(1.5f, 1.2f);

    // error! : argument types are different
    // double d = sumTemplate(1.5, 1.2f); 

    std::cout << "int = " << i << std::endl;
    std::cout << "float = " << f << std::endl;
    // std::cout << "double = " << d << std::endl;

    return 0;
}