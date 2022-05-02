#include <iostream>

using namespace std;

class RectConst
{
public:
    constexpr RectConst(size_t width, size_t height)
        : myWidth(width), myHeight(height)
    {
    }

    constexpr size_t getArea() const
    {
        return myWidth * myHeight;
    }

private:
    int myWidth;
    int myHeight;
};

class Rect
{
public:
    Rect(size_t width, size_t height)
        : myWidth(width), myHeight(height)
    {
    }

    size_t getArea() const
    {
        return myWidth * myHeight;
    }

private:
    int myWidth;
    int myHeight;
};

int main()
{
    RectConst rectConst{8, 2};
    int array[rectConst.getArea()];

    cout << "getArea = " << rectConst.getArea() << endl;

    Rect rect{8, 2};
    //int array[rect.getArea()];  // Error. conflicting declaration 'int array [<anonymous>]'

    return 0;
}