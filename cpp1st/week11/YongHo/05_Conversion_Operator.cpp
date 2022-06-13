#include <iostream>

// https://www.geeksforgeeks.org/operator-overloading-c
// Conversion Operator : We can also write conversion operators that can be used to convert one type to another type.

class Fraction
{
    private:
        int num, den;
    public:
        Fraction(int n, int d)
        {
            num = n;
            den = d;
        }

        //Conversion operator: return float value of fraction
        operator float() const
        {
            return float(num) / float(den);
        }
};

int main()
{
    Fraction f(2, 5);
    float val = f;
    std::cout << val << std::endl;
    return 0;
}