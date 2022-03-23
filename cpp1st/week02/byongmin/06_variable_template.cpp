// variable template

#include <iostream>
#include <string>

using namespace std;

template<typename T>
constexpr T pi = T(3.1415926535897932385L);

template<>
constexpr char const *pi<char const *> = "pi";

int main()
{
    int i = pi<int>;
    float f = pi<float>;
    double d = pi<double>;
    char const *s = pi<char const *>;
    //string str = pi<string>;      // error! std::string is not literal type

    cout << "int : " << i << endl;
    cout << "float : " << f << endl;
    cout << "double : " << d << endl;
    cout << "char const * : " << s << endl;
    //cout << "string : " << str << endl;

    return 0;
}