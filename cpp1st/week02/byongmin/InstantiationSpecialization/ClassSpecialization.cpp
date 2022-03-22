// PartialSpecializeTemplate
// https://en.wikipedia.org/wiki/Partial_template_specialization

#include <iostream>

using namespace std;

template <typename Key, typename Value>
class KeyValuePair
{
public : KeyValuePair() { cout << "Primary (Key, Value)" << endl; }                                 // (1)
};

template <>
class KeyValuePair<int, string> 
{
public: KeyValuePair() { cout << "full specialization (int, string)" << endl; }                     // (2)
};

template <typename Key>
class KeyValuePair<Key, string> 
{
public: KeyValuePair() { cout << "partial specialization (Key, string)" << endl; }                  // (3)
};

template <typename Key>
class KeyStringPair : public KeyValuePair<Key, string> 
{
public: KeyStringPair() { cout << "partial specialization KeyStringPair(Key)" << endl; }            // (4)
};

template <typename Value>
class IntegerValuePair : public KeyValuePair<int, Value> 
{
public: IntegerValuePair() { cout << "partial specialization IntegerValuePair(Value)" << endl; }    // (5)
};

int main()
{
    KeyValuePair<int, float> data1;     // print (1)
    cout << endl;
    KeyValuePair<int, string> data2;    // print (2)
    cout << endl;
    KeyValuePair<short, string> data3;  // print (3)
    cout << endl;
    KeyStringPair<short> data4;         // print (3) and (4)
    cout << endl;
    IntegerValuePair<int> data5;        // print (1) and (5)

    return 0;
}

