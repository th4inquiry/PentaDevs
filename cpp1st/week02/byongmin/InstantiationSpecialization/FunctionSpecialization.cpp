// FunctionSpecialization
// https://en.wikipedia.org/wiki/Partial_template_specialization

#include <iostream>
#include <string>

using namespace std;

template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType arg);

// legal: explicit/full function template specialization
template <>
std::string Foo<std::string, char>(char arg) 
{ 
    return "Full"; 
}

// legal: overloads the base template for a pointer argument type
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType* argPtr) 
{ 
    return "PtrOverload"; 
}

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ArgumentType>
string Foo(ArgumentType arg) 
{ 
    return "Return1"; 
}

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ReturnType>
ReturnType Foo(char arg) 
{ 
    return "Return2"; 
}

int main()
{
    char c = 'c';
    string r0, r1, r2, r3;
    
    // let the compiler resolve the call
    r0 = Foo(c);
    
    // explicitly specify which function to call
    r1 = Foo<string>(c);
    r2 = Foo<string, char>(c);
    r3 = Foo<string, char>(&c);
    
    // generate output
    cout << r0 << endl << r1 << endl << r2 << endl << r3 << endl;

    return 0;
}

