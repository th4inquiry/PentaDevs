// variable template

#include <iostream>

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

    cout << "int : " << i << endl;
    cout << "float : " << f << endl;
    cout << "double : " << d << endl;
    cout << "char const * : " << s << endl;

    return 0;
}