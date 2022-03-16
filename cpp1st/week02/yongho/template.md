# Template

Templates are powerful features of C++ which allows us to write generic programs.
The simple idea is to pass data type as a parameter so that we don't need to write the same code for different data types.
C++ adds two new keywords to support templates: 'template' and 'typename'. The second keyword can always be replaced by keyword 'class'.

How do template work?
Templates are expanded at compiler time. This is like macros.
The difference is, the compiler does type checking before template expansion.
The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.

## Class Templates

Class templates are useful when a class defines something that is independent of the data type.
Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc.

### Declaration

A class template starts with the keyword template followed by template parameter(s) inside <> which is followed by the class declaration.

```C++
template <class T>
class className {
	private:
		T var;
	public:
		T functionName(T arg);
	... .. ...
};
```
In the above declration, T is the template argument which is a placeholder for the data type used, and class is a keyword.
Inside the class body, a member variable var and a member function functionName() are both of type T.

### Creating a object

Once we've declared and defined a class template, we can create its objects in other classes 
or functions (such as the main() function) with the following syntax.
'''
className<dataType> classObject;
'''

For example
'''
className<int> classObject;
className<float> classObject;
className<string> classObject;
'''

### Defining a Class Member Outside

Suppose we need to define a function outside of the class template, We can do this with the following code:
'''
template <class T>
class ClassName {
	....
	//Function prototype
	returnType functionName();
};

//Function definition
template <class T>
returnType ClassName<T>::functionName() {
	//code
}
'''
Notice that the code "template <class T>" is repeated while defining the function outside of the class.
This is necessary and is part of the syntax.

### Multiple Parameters(Arguments)
In C++, we can use multiple template parameters and even use default arguments for those parameters.

'''
template <class T, class U, class V = int>
class ClassName {
	private:
		T member1;
		U member2;
		V member3;
	public:
		...
}
'''

### Default value
We can specify default arguments to templates.

'''
template<class T, class U = char>
class A {
	public:
		T x;
		U y;
		A() { cout << "Constructor Called" << endl; }
};
'''

## Function Templates

We can create generic function to work with different data types by using a template.
Examples of function templates are sort(), max(), min(), printArray().

### Defining
A function templates starts with the keyword template followed by template parameter(s) inside <> which is followed by the function definition.

'''
template <typename T>
T functionName(T parameter1, T parameter2, ...) {
	//code
}
'''
In the above code, T is a template argument that accepts different data types (int, float, etc.), and typename is a keyword.
When an argument of a data type is passed to functionName(), the compiler generates a new version of functionName() for the given data type.

### Calling
Once we've declared and defined a function template, we can call it in other functions or templates (such as the main() function) with the following syntax
'''
functionName<dataType>(parameter1, parameter2, ...);
'''
For example, let us consider a template that adds two numbers:
'''
template <typename T>
T add(T num1, T num2) {
	return (num1 + num2); 
}
'''

We can then call it in the main() function to add int and double numbers.

'''
int main() {
	int result1;
	double result2;
	//calling with int parameters
	result1 = add<int>(2,3);
	cout << result1 << endl;

	//calling with double parameters
	result2 = add<double>(2.2, 3.3);
	cout << result2 << endl;
}
'''
### function overloading and templates
Both function overloading and templates are example of polymorphism feature of OOP.
Function overloading is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.

### static variables and templates
Each instantiation of function template has its own copy of local static variables.
'''
template <typename T>
void fun(const T& x)
{
	static int i=10;
	cout << ++i;
	return;
}

int main()
{
	fun<int>(1); //prints 11
	cout << endl;
	fun<int>(2); //prints 12
	cout << endl;
	fun<double>(1.1); //prints 11
	cout << endl;
	getchar();
	return 0;
}
'''
The rule for class templates is same as function templates
Each instantiation of class template has its own copy of member static variables.

'''
template <class T>class Test
{
	private:
		T val;
	public:
		static int count;
		Test()
		{
			count++;
		}
		//some other stuff in class
}

template<class T>
int Test<T>::count = 0;

int main()
{
	Test<int> a; //value of count for Test<int> is 1 now
	Test<int> b; //value of count for Test<int> is 2 now
	Test<double> a; //value of count for Test<double> is 1 now
	cout << Test<int>::count << endl; //prints 2
	cout << Test<double>::count << endl; //prints 1
	getchar();
	return 0;
}
'''
#### Can we pass nontype parameter to templates?
We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values
or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is,
they must be const. The complier must know the value of non-type paramters at compile time. Because the compiler
needs to create functions/classes for a specified non-type value at compile time. In below program, if we replace 10000 or 25 with a variable,
we get a compiler error.

'''
template <class T, int max>
int arrMin(T arr[], int n)
{
	int m=max;
	for (int i=0; i < n ; i++)
		if (arr[i] < m)
			m=arr[i]

	return m;
}

int main()
{
	int arr1[] = {10, 20, 15, 12};
	int n1 = sizeof(arr1)/sizeof(arr1[0]]);

	char arr2[] = {1, 2, 3};
	int n2 = sizeof(arr2)/sizeof(arr2[0]]);

	//Second template parameter to arrMin must be a constant
	cout << arrMin<int, 10000>(arr1, n1) << endl;  //prints 10
	cout << arrMin<char, 256>(arr2, n2); //prints 1
	return 0;
}

'''


## Template Specialization
Template in C++ is a feature. We write code once and use it for any data type including user defined data types.
For example, sort() can be written and used to sort any data type items.
A class stack can be created that can be used as a stack of any data type.
What if we want a different code for a particular data type? 
Consider a big project that needs a function sort() for arrays of many different data types.
Let Quick Sort be used for all datatypes except char.
In case of chr, total possible values are 256 and counting sort may be a better option.
Is it possible to use different code only when sort() is called for char data type?
It is possible in C++ to get a special behavior for a particular data type.
This is called template specialization.

'''
//A generic sort function
template <class T>
void sort(T arr[], int size)
{
	//code to implement Quick Sort
}

//Template Specialization: A function
//specialized for char data type
template<>
void sort<char>(char arr[], int size)
{
	//code to implement counting sort
}
'''
Another example could be a class Set that represents a set of elements and supports operations like union, intersection, etc.
When the type of elements is char, we may want to use a simple boolean array of size 256 to make a set.
For other data types, we have to use some other complex technique.

### function template specialization

For example, consider the following simple code where we have general template fun() for all data types except int.
For int, there is a specialized version of fun().

'''
template <class T>
void fun(T a)
{
	cout << "The main template fun(): " << a << endl;
}

template<>
void fun(int a)
{
	cout << "Specialized Template for int type: " << a << endl;
}

int main()
{
	fun<char>('a');  //The main template fun(): a
	fun<int>(10);  //Specialized Template for int type: 10
	fun<float>(10.14);  //he main template fun(): 10.14
}
'''
### class template specialization
In the following program, a specialized version of class Test is written for int data type.

'''
template <class T>
class Test
{
	//Data members of test
	public:
		Test()
		{
			//Initialization of data members
			cout << "General template object \n";
		}
		//Other methods of Test
}

template<>
class Test <int>
{
public:
	Test()
	{
		//Initialization of data members
		cout << "Specialized template object\n";
	}
};

int main()
{
	Test<int> a;  //Specialized template object
	Test<char> b; //General template object
	Test<float> c; //General template object
	return 0;
}
'''
#### How does template specialization work?
When we write any template based function or class, compiler creates a copy of that function/class 
whenever compiler sees that being  used for a new data type or new set of data types(in case of multiple template arguments).
If a specializaed version is present, compiler first checks with the specialized version and then the main template.
Compiler first checks with the most specialized version by matching the passed parameter with the data type(s) specified

#### Reference
https://www.programiz.com/cpp-programming/class-templates
https://www.programiz.com/cpp-programming/function-template
https://www.geeksforgeeks.org/templates-cpp/

* :octocat:
