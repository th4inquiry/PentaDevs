#include <iostream>

// https://www.geeksforgeeks.org/operator-overloading-c/
// Any constructor that can be called with a single argument works as a conversion constructor,
// which means it can also be used for implicit conversion to the class being constructed.

class Point
{
    private:
        int x, y;
    public:
        Point(int i=0, int j=0)
        {
            x = i;
            y = j;
        }
        
        void print()
        {
            std::cout << "x = " << x << ", y= " << y << std::endl;
        }
};

int main()
{
    Point t(20, 20);
    t.print();
    t = 30; //Member x of t becomes 30
    t.print();
    
    return 0;
}