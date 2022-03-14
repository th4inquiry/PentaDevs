#include <functional>
#include <iostream>

using namespace std;

void DeclaringLambda();
void ImmediatelyRunLambda();
void CaptureLambda();
void AlgorithmLambda();
void NestingLambda();
void HighOrderLambda();

int main()
{
    DeclaringLambda();
    ImmediatelyRunLambda();
    CaptureLambda();
    AlgorithmLambda();
    NestingLambda();
    HighOrderLambda();

    return 0;
}

void DeclaringLambda()
{
    cout << endl;
    cout << "++ DeclaringLambda()" << endl;

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;
}

void ImmediatelyRunLambda()
{
    cout << endl;
    cout << "++ ImmediatelyRunLambda()" << endl;

    // declalation + explicit return type (int)
    std::function<int(int,int)> f1 = [](int x, int y) -> int { return x + y; };

    // immediately run
    int f2 = [](int x, int y) { return x + y; }(3, 4);

    cout << f1(3, 4) << endl;
    cout << f2 << endl;
}


void CaptureLambda()
{
    cout << endl;
    cout << "++ CaptureLambda()" << endl;

    int i = 10;
    int j = 10;

    auto f = [i, &j] {return i + j; };

    cout << f() << endl;

    i = 20;
    j = 20;

    cout << f() << endl;
}

void AlgorithmLambda()
{
    cout << endl;
    cout << "++ AlgorithmLambda()" << endl;

    vector<int> vec = { 1, 2, 3, 4, 5 };
    auto isEven = [](int num) {return num%2 == 0; };
    auto result = find_if(vec.begin(), vec.end(), isEven);

    cout << "first even value in element = " << *result << endl;
}

void NestingLambda()
{
    cout << endl;
    cout << "++ NestingLambda()" << endl;

     int value = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);

    // Print the result.
    cout << value << endl;   
}

// A higher-order function is a lambda expression that 
// takes another lambda expression as its argument 
// or returns a lambda expression
void HighOrderLambda()
{
    cout << endl;
    cout << "++ HighOrderLambda()" << endl;

    auto addtwointegers = [](int x) -> function<int(int)> {
        return [=](int y) { return x + y; };
    };

    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    auto answer = higherorder(addtwointegers(7), 8);

    // Print the result, which is (7+8)*2.
    cout << answer << endl;
}