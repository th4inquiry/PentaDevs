# Template

Templates are powerful features of C++ which allows us to write generic programs.
The simple idea is to pass data type as a parameter so that we don't need to write the same code for different data types.
C++ adds two new keywords to support templates: **'template'** and **'typename'**. The second keyword can always be replaced by keyword **'class'**.

How do template work?
Templates are expanded at compiler time. This is like macros.
The difference is, the compiler does type checking before template expansion.
The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.

Templates are a way of making your classes more abstract by letting you define the behavior of the class without actually knowing 
what datatype will be handled by operations of the class. Templates can be used in conjunction with abstract datatypes in order to allow
them to handle any type of data.

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
parameter-list : a non-empty comma-separated list of the template paramters, each of which is eitther a non-type parameter,
a type parameter, a template parameter, or a parameter pack of any of those.
Inside the class body, a member variable var and a member function functionName() are both of type T.

### Creating a object

Once we've declared and defined a class template, we can create its objects in other classes 
or functions (such as the main() function) with the following syntax.
```C++
className<dataType> classObject;
```

For example
```C++
className<int> classObject;
className<float> classObject;
className<string> classObject;
```

### Class template instantiation

A class template by itself is not a type, or an object, or any other entity. No code is generated from a source file that
contains only template definitions. In order for any code to appear, a template must be instantiated: the template arguments
must be provided so that the compiler can generate an actual class (or function, from a function template).

#### Explicit instantiation

Classes, functions, variables and member template specializations can be explicitly instantiated from their templates.
Member functions, member classes, and static data members of class templates can be explicitly instantiated from their member definitions.
Explicit instantiation can only appear in the enclosing namespace of the template, unless it uses qualified-id:

```C++
namespace N
{
	template<class T>
	class Y //template definition
	{
		void mf() {}
	}
}

//template class Y<int>; //error: class template Y not visible in the global namespace
using N::Y;
//template class Y<int>; //error: explicit instantiation outside of the namespace of the template
template class N::Y<char*>; //OK: explicit instantiation
template void N::Y<double>::mf(); //OK: explicit instantiation
```

#### Implicit instantiation

When code refers to a template in context that requires a completely defined type, or when the completeness of the type affects the code,
and this particular type has not been explicitly instantiated, implicit instantiation occurs.
For example when an object of this type is constructed, but not when a pointer to this type is constructed.

This applies to the members of the class template: unless the member is used in the program, it is not instantiated, and does not require a definition.

```C++
template<class T>
struct Z //template definition
{
	void f() {}
	void g(); //never defined
}

template struct Z<double>; //explicit instantiation of Z<double>
Z<int> a;	//implicit instantiation of Z<int>
Z<char>* p; //nothing is instantiated here

p->f(); //implicit instantiation of Z<char> and Z<char>::f() occurs here.
			//z<char>::g() is never needed and never instantiated:
			//it does not have to be defined
```

If a class template has benn declared, but not defined, at the point of instantiation, the instantiation yields an incomplete class type:

```C++
template<class T>
class X; //declaration, not definition

X<char> ch;	//error: incomplete type X<char>
```

### Defining a Class Member Outside

Suppose we need to define a function outside of the class template, We can do this with the following code:
```C++
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
```

Notice that the code "template <class T>" is repeated while defining the function outside of the class.
This is necessary and is part of the syntax.

### Multiple Parameters(Arguments)
In C++, we can use multiple template parameters and even use default arguments for those parameters.

```C++
template <class T, class U, class V = int>
class ClassName {
	private:
		T member1;
		U member2;
		V member3;
	public:
		...
}
```

### Default value
We can specify default arguments to templates.

```C++
template<class T, class U = char>
class A {
	public:
		T x;
		U y;
		A() { cout << "Constructor Called" << endl; }
};
```

This is class template example

```C++
template <class T>
class mypair 
{
	T a, b;
	public:
		mypair(T first, T second)
		{
			a=first;
			b=second;
		}
		T getmax();
}

template <class T>
T mypair<T>::getmax()
{
	T retval;
	retval = (a>b)? a:b;
	return retval;
}

int main()
{
	mypair <int> myobject (100, 75);
	cout << myobject.getmax();
	return 0;
}
```



## Function Templates

We can create generic function to work with different data types by using a template.
Examples of function templates are sort(), max(), min(), printArray().

Function templates are special functions that can operate with generic types.
This allow us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.

In C++, this can be achieved using template parameters.
A template parameter is a special kind of parameter that can be used to pass a type as argument: just like regular function paramters can be
used to pass values to a function, template paramters allow to pass also types to a function. These function templates can use these parameters
as if they were any other regular type.

### Defining
A function templates starts with the keyword template followed by template parameter(s) inside <> which is followed by the function definition.

```C++
template <typename T>
T functionName(T parameter1, T parameter2, ...) {
	//code
}

template <class T>
T functionName(T parameter1, T parameter2, ...) {
	//code
}
```

In the above code, T is a template argument that accepts different data types (int, float, etc.), and typename is a keyword.
When an argument of a data type is passed to functionName(), the compiler generates a new version of functionName() for the given data type.

The only difference between both prototype is the use of either the keyword class or the keyword typename.
Its use is indistinct, since both expressions have exactly the same meaning and behave exactly the same way.

### Calling
Once we've declared and defined a function template, we can call it in other functions or templates (such as the main() function) with the following syntax

```C++
functionName<dataType>(parameter1, parameter2, ...);
```

For example, let us consider a template that adds two numbers:

```C++
template <typename T>
T add(T num1, T num2) {
	return (num1 + num2); 
}
```

We can then call it in the main() function to add int and double numbers.

```C++
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
```

Other example from cplusplus.com 
```C++
//function template
template <class T>
T GetMax (T a, T b)
{
	T result;
	result = (a>b)? a : b;
	return result;
}

int main()
{
	int i=5. j=6, k;
	long l=10, m=5, n;
	k = GetMax<int>(i,j);
	n = GetMax<long>(l,m);
	cout << k << endl;	//prints 6
	cout << n << endl;	//prints 10

	//This expression is also working. The compiler can automatically find out template parameter type.
	k = GetMax(i,j);
	n = GetMax(l,m);
	cout << k << endl;	//prints 6
	cout << n << endl;	//prints 10
	return 0;
}
```

When you want to use different type in two parameters. We can also define function templates that accept
more than one type parameter,simply by specifying more template paramters between the angle brackets.

```C++
//function template
template <class T, class U>
T GetMax (T a, U b)
{
	return (a>b)? a : b;
}

int main()
{
	int i=5, k;
	long l=10;
	k = GetMax<int, long>(i,l);
	cout << k << endl;	//prints 10

	//This expression is also working. The compiler can automatically find out template parameter type.
	k = GetMax(i,j);
	cout << k << endl;	//prints 10
	return 0;
}
```

### function overloading and templates
Both function overloading and templates are example of polymorphism feature of OOP.
Function overloading is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.

### static variables and templates
Each instantiation of function template has its own copy of local static variables.

```C++
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
```

The rule for class templates is same as function templates
Each instantiation of class template has its own copy of member static variables.

```C++
template <class T>
class Test
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
```

#### Can we pass nontype parameter to templates?
We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values
or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is,
they must be const. The complier must know the value of non-type paramters at compile time. Because the compiler
needs to create functions/classes for a specified non-type value at compile time. In below program, if we replace 10000 or 25 with a variable,
we get a compiler error.

```C++
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
```

This is non-type parameters sample code from Cplusplus.com

```C++
template <class T, int N>
class mySequence
{
	T memBlock[N];
	public:
		void setMember(int x, T value);
		T getMember(int x);
}

template <class T, int N>
void mySequence<T, N>::setMember (int x, T value)
{
	memBlock[x]=value;
}

template <class T, int N>
T mySequence::getMember(int x)
{
	return memBlock[x];
}

int main()
{
	mySequence <int, 5> myInts;
	mySequence <double, 5> myFloats;
	myInts.setMember (0, 100);
	myFloats.setMemver (3, 3.1416);
	cout << myInts.getMember(0) << '\n';	//prints 100
	cout << myFloats.getMember(3) << '\n';	//prints 3.1415
	return 0;
}
```
It is also possible to set default values or types for class template parameters. For example, if the previous class
template definition had been:

#### Templated Classes with Templated Functions
It is also possible to have a templated class that has a member function that is itself a template, separate from the class template.
For instance,

```C++
template <class type> class TClass
{
	//constructors..etc

	template <class type2> type2 myFunc(type2 arg);
}
```
The function myFunc is a templated function inside of a templated class, and when you actually define the function,
you must respect this by using the template keyword twice:

```C++
template <class type> //For the class
	template <class type2> //For the function
	type2 TClass<type>::myFunc(type2 arg)
	{
		//code
	}
```
The follwing attempt to combine the two is wrong and will not work:

```C++
//wrong code
template <class type, class type2> type2 TClass<type>::(type2 arg)
{
	//code
}
```
because it suggests that the template is entirely the class template and not a function template at all.

```C++
template <class T=char, int N=10> class mySequence {...};
```
We could create objects using the default parameters by declaring:

```C++
mySequence<> mySeq;
mySequence<char, 10> mySeq; //This would be equivalent with upperline
```

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

```C++
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
```
Usually when writing code it is easiest to precede from concrete to abstract; therefore, it is easier to write a class for a 
specific datatype and then proceed to a templated -generic-class.

Another example could be a class Set that represents a set of elements and supports operations like union, intersection, etc.
When the type of elements is char, we may want to use a simple boolean array of size 256 to make a set.
For other data types, we have to use some other complex technique.

In many cases when working with templates, you'll write on generic version for all possible data types and leave it at that-every vector
may be implemented in exactly the same way. The idea of template specialization is to override the default 

**The idea of template specialization is to override the default template implementation to handle a particular type in a different way.**

### function template specialization

For example, consider the following simple code where we have general template fun() for all data types except int.
For int, there is a specialized version of fun().

```C++
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
	fun<float>(10.14);  //The main template fun(): 10.14
}
```

### class template specialization
In the following program, a specialized version of class Test is written for int data type.

```C++
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
```

template specialization sample from cplusplus.com

```C++
//class template
template <class T>
class mycontainer
{
	T element;
	public:
		mycontainer (T arg)
		{
			element = arg;
		}
		T increase()
		{
			return ++element;
		}
}

//clss template specialization:
template<>
class mycontainer <char>
{
	char element;
	public:
		mycontainer (char arg)
		{
			element = arg;
		}

		char uppercase()
		{
			if ((element >= 'a') && (element <='z'))
				element +='A'-'a';
			return element;
		}
};

int main()
{
	mycontainer<int> myint(7);	
	mycontainer<char> mychar('j');
	cout << myint.increase() << endl; //prints 8
	cout << mychar.uppercase() << endl; //prints J
	return 0;
}

```

First of all, notice that we precede the class template name with an empty template<> parameter list.
This is to explicitly declare it as a template specialization.
But more importaint than this prefix, is the <char> specialization parameter after the class template name.
This specialization parameter itself the type for which we are going to declare a template class specialization (char).
Notice the differences between the generic class template and the specialization:

```C++
template <class T> class mycontainer {...}; //generic template
template <> class mycontainer <char> {...}; //specialization
```
When we declare specializations for a template class, we must also define all its members, even those exactly equal to 
the generic template class, because there is no "inheritance" of members from the generic template to the specialization.


#### Template Partial Specialization
Partial template specialization stems from similar motives as full specialization. This time, however, instead of implementing a class
for one specific type, you end up implementing a template that still allows some parameterization. That is, you write a template that 
specializes on one feature but still lets the class user choose other features as part of the template.

Going back to the idea of extending the concept of vectors so that we can have a sortedVector, let's think about how this might look:
we'll need a way of making comparisons. Fine; we can just use > if it's been implemented, or specialize if it hasn't. But now let's say that
we wanted to have pointers to objects in our sorted vector. We could sort them by the value of the pointers, just doing a standard > comparison
(we'll have a vector sorted from low to high):

```C++
template <typename T>
class sortedVector
{
	public:
		void insert (T val)
		{
			if (length == vec_size)	//length is the number of elements
			{
				vec_size *= 2;	//we'll just ignore overflow possibility!
				vec_data = new T[vec_size];
			}
			++length; //we are about to add an element

			//we'll start at the end, sliding elements back until we find the
			//place to insert the new element
			int pos;
			for(pos = length; pos > 0 && val > vec_data[pos-1]; --pos)
			{
				vec_data[pos] = vec_data[pos-1];
			}
			vec_data[pos] = val;
		}

	//other methods..
	private:
		T *vec_data;
		int length;
		int size;
};
```
Now, notice that in the above for loop, we're making a direct comparison between elements of type T. That's OK for most things,
but it would probably make more sense to have sorted on the actual object type instead of the pointer address.
To do that, we'd need to write code that had this line:

```C++
for(pos = length; pos > 0 && *val > *vec_data[pos-1]; --pos)
```

Of course, that would break for any non-pointer type. What we want to do here is use a partial specialization based on
whether the type is a pointer or a non-pointer (you could get fancy and have multiple levels of pointers, but we'll stay simple.)

To declare a partially specialized template that handles any pointer types, we'd add this class declaration:

```C++
template <typename T>
class sortedVector<T *>
{
	public:
		//same functions as before. Now the insert function looks like this:
		insert(T *val)
		{
			if (length == vec_size)	//length is the number of elements
			{
				vec_size *= 2;	//we'll just ignore overflow possibility!
				vec_data = new T[vec_size];
			}
			++length; //we are about to add an element

			//we'll start at the end, sliding elements back until we find the
			//place to insert the new element
			int pos;
			for(pos = length; pos > 0 && *val > *vec_data[pos-1]; --pos)
			{
				vec_data[pos] = vec_data[pos-1];
			}
			vec_data[pos] = val;
		}

	private:
		T** vec_data;
		int length;
		int size;
}
```
There are a couple of syntax points to notice here. 

First, our template paramter list still names T as the parameter, but the declaration now has a T* after the name of the class; 
this tells the compiler to match a pointer of any type with this template instead of the more general template.

The second thing to note is that T is now the type pointed to ;**it is not itself a pointer.**
For instance, when you declare a sortedVector<int *>, T will refer to the int type! This makes some sense if you think of it
as a form of pattern matching where T matches the type if that type is followed by an asterisk.
This does mean that you have to be a tad bit more careful in your implementation: note that vec_data is a T** 
because we need a dynamically sized array made up of pointers.

You might wonder if you really want your sortedVector type to work like this--after all, if you're putting them in an array of pointers,
you'd expect them to be sorted by pointer type. But there's a practical reason for doing this: when you allocate memory for an array of objects,
the default constructor must be called to construct each object. If no default constructor exists (for instance, if every object need some data 
to be created), you're stuck needing a list of pointers to objects, but you probabley want them to be sorted the same way the actual objects themselves would be!

Note, by the way, that you can also partially specialize on template arguments--for instance, if yoy had a fixedVector type that allowed the
user of the class to specify both a type to store and the length of the vector (possibly to avoid the cost of dynamic memory allocations),
it might look something like this:

```C++
template <typename T, unsigned length>
class fixedVector { ... };
```
Then you could partially specialize for booleans with the following syntax

```C++
template <unsigned length>
class fixedVector<bool, length> { ... };
```
Note that since T is no longer a template parameter, it's left out of the template paramter list, leaving only length.
Also note that length now shows up as part of fixedVector's name (unlike when you have a generic template declaration, 
where you specify nothing after the name). (By the way, don't be surprised to see a template parameter that's a non-type:
it's perfectly valid, and sometimes useful, to have template arguments that are integer types such as unsigned.)

A final implementation detail comes up with partial specializations: how does the compiler pick which specialization to use
if there are a combination of completely generic types, some partial specializations, and maybe even some full specializations?
The general rule of thumb is that the compiler will pick the most specific template specialization--the most specific template
specialization is the one whose template arguments would be accepted by the other template decalrations, but which would
not accept all possible arguments that other templates with the same name would accept.

For instance, if you decided that you wanted a sortedVector<int *> that sorted by memory location, you could create a 
full specialization of sortedVector and if you declared a sortedVector<int*>, then the compiler would pick that implementation
over the the less-specific partial specialization for pointers. It's the most specialized since only an int * matches the full
specialization, not any other pointer type such as a double *, wheres int * certainly could be a paramter to either of the other templates.


#### How does template specialization work?

When we write any template based function or class, compiler creates a copy of that function/class 
whenever compiler sees that being  used for a new data type or new set of data types(in case of multiple template arguments).
**If a specializaed version is present, compiler first checks with the specialized version and then the main template.**
Compiler first checks with the most specialized version by matching the passed parameter with the data type(s) specified

### Templates and multiple-file projects

From the point of view of the compiler, templates are not normal functions or classes. They are compiled on demand,
meaning that code of a template function is not compiled until an instantiation with specific template arguments is required.
At that moment, when an instantiation is required, the compiler generates a function specially for the those arguments from the template.

When projects grow it is usual to split the code of a program in different source code files. In these cases, the interface and implementation
are generally separated. Taking a library of functions as example, the interface generally consists of declarations of the prototypes of all
the functions that can be called. These are genenrally declared in a "header file" with a .h extension, and the implementation
(the definition of these functions) is in and independent file with c++ code.

Because templates are compiled when required, this forces a restriction for multi-file projects: **the implementation (definition) of a template class
or function must be in the same file as its declaration. That means that we cannot separate the interface in s separate header file, and that
we must include both interface and implementation in any file that uses the templates.**

Since no code is generated until a template is instantiated when required, compilers are prepared to allow the inclusion more than once
of the same template file with both declarations and definitions in a project without generating linkage errors.


#### Reference
<https://www.programiz.com/cpp-programming/class-templates>

<https://www.programiz.com/cpp-programming/function-template>

<https://www.geeksforgeeks.org/templates-cpp/>

<https://www.cprogramming.com/tutorial/templated_functions.html>

<https://www.cprogramming.com/tutorial/template_specialization.html>

<https://www.cplusplus.com/doc/oldtutorial/templates/>

<https://en.cppreference.com/w/cpp/language/class_template>

* :octocat:
