// LambdaExpression_examples.cpp : Various lambda expression //

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <thread>

/// <summary>
/// Simple Person class for testing lambda expression
/// </summary>
class Person
{
public:
	// constructor
	Person(std::wstring _name, int _age) : name(_name), age(_age)
	{
		std::wcout << L"Person consturctor" << std::endl;
	}
	// copy constructor
	Person(const Person& person) : name(person.name), age(person.age)
	{
		std::wcout << L"Person copy constructor" << std::endl;
	}
	// move constructor
	Person(Person&& person) noexcept : name(person.name), age(person.age)
	{
		std::wcout << L"Person move constructor" << std::endl;
		person.name = L"";
		person.age = 0;
	}
	// copy assignment
	Person& operator=(const Person& person) noexcept
	{
		std::wcout << L"Person copy assigment" << std::endl;
		name = person.name;
		age = person.age;
		return *this;
	}
	// move assigment
	Person& operator=(Person&& person) noexcept
	{
		std::wcout << L"Person move assigment" << std::endl;
		name = person.name;
		age = person.age;
		person.name = L"";
		person.age = 0;
		return *this;
	}

	~Person()
	{
		std::wcout << __FUNCTIONW__ << std::endl;
	}

	void printInfo() const
	{
		std::wcout << L"name : " << name << " | age : " << age << std::endl;
	}

private:

	std::wstring name;
	int age;
};

/// <summary>
/// LambdaTest class for testing lambda expression examples
/// </summary>
class LambdaTest
{
public:

	/// <summary>
	/// capture [=, *this] test
	/// </summary>
	void test0()
	{
		std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;
		Person tempPerson(L"Jack", 10);
		auto lambdaExp = [=, *this]() mutable {
			mPerson0 = tempPerson;
			mPerson1 = tempPerson;
			mPerson0.printInfo();
			mPerson1.printInfo();
			PrintHello();
		};
		lambdaExp();
		this->mPerson0.printInfo();
		this->mPerson1.printInfo();
	}

	/// <summary>
	/// caputre expression test
	/// </summary>
	void test1()
	{
		std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;
		double pi = 3.1415;
		auto lambdaExp = [myCapture = L"Pi : ", pi] { std::wcout << myCapture << pi << std::endl; };
		lambdaExp();
	}

	/// <summary>
	/// capture expression test using smart pointer
	/// </summary>
	void test2()
	{
		std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;
		auto personPtr = std::make_unique<Person>(L"Jongsang", 40);
		auto lambdaExp = [myPersonPtr = std::move(personPtr)]{ myPersonPtr->printInfo(); };
		lambdaExp();
		
		// Note that unique_ptr's assignment operator only accepts rvalues, 
		// which are typically generated by std::move. 
		// (The unique_ptr class explicitly deletes its lvalue copy constructor 
		// and lvalue assignment operator.)
	}

	/// <summary>
	/// return lambda expression test
	/// </summary>
	void test3()
	{
		std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;
		auto lambdaExp = multBy10Lambda(12);
		std::wcout << L"Result of lambda : " << lambdaExp() << std::endl;
	}

	/// <summary>
	/// Generic lambda expression test
	/// </summary>
	void test4()
	{
		auto lambdaExp = [](auto val) {
			return val > 50;
		};

		std::vector<int> vecInt{ 34, 56, 11, 63, 77, 86, 99 };
		auto cnt0 = count_if(vecInt.begin(), vecInt.end(), lambdaExp);
		std::wcout << L"Vector contains " << cnt0 << std::endl;

		std::vector<double> vecDouble{ 54.3, 22.1, 23.5, 32.6, 66.5 };
		auto cnt1 = count_if(vecDouble.begin(), vecDouble.end(), lambdaExp);
		std::wcout << L"Vector contains " << cnt1 << std::endl;
	}

	/// <summary>
	/// Thread test with lambda expression
	/// </summary>
	void test5(void)
	{
		int loopCount = 5;
		std::thread t1{ [loopCount]() {
			for (int i = 0; i < loopCount; ++i)
			{
				std::wcout << L"Thread test : " << i << std::endl;
			}
		} };
		t1.join();
	}

private:
	std::function<int(void)> multBy10Lambda(int x)
	{
		return [x] {return x * 10; };
	}

	void PrintHello()
	{
		std::wcout << L"Hello, this is private method" << std::endl;
	}

	Person mPerson0 = { L"Big brother0", 40 };
	Person mPerson1 = { L"Big brother1", 40 };
};

int main()
{
	LambdaTest lambdaTest;
	lambdaTest.test0();
	lambdaTest.test1();
	lambdaTest.test3();
	lambdaTest.test4();
	lambdaTest.test5();

	return 0;
}

