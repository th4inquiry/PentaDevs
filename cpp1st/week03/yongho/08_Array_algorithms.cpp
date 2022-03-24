#include <iostream>
#include <algorithm> //for all_of, any_of, none_of, copy_n
#include <numeric>   //for iota

int main()
{
	//Initializing array
	int arr[] = { 1,2,3,4,5,-6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Initial array : \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	//Checking if all elements are positive
	std::cout << "\n\nChecking if all elements are positive : \n";
	std::all_of(arr, arr + n, [](int x) {return x > 0; }) ?
		std::cout << "All are positive elements" :
		std::cout << "All are not positive elements";

	//Checking if any element is negative
	std::cout << "\n\nChecking if any element is negative: \n";
	std::any_of(arr, arr + n, [](int x) {return x < 0; }) ?
		std::cout << "There exists a negative element" :
		std::cout << "All are positive elements";

	//Checking if no element is negative
	std::cout << "\n\nChecking if no element is negative: \n";
	std::none_of(arr, arr + n, [](int x) {return x < 0; }) ?
		std::cout << "No negative elements" :
		std::cout << "There are negative elements";

	//Initializing array
	int arr1[] = { 1,2,3,4,5,6 };
	const int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[arr1_size];

	//Using copy_n() to copy contens
	std::copy_n(arr1, arr1_size, arr2);

	//Displaying the copied array
	std::cout << "\n\nThe new array after copying is : \n";
	for (int i = 0; i < arr1_size; i++)
		std::cout << arr2[i] << " ";

	//Initializing array with 0 values
	int arr3[6] = { 0 };
	int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

	//Using iota() to assign values
	std::iota(arr3, arr3 + arr3_size, 20);

	//Displaying the new array
	std::cout << "\n\nThe new array after assigning values is : \n";
	for (int i = 0; i < arr3_size; i++)
		std::cout << arr3[i] << " ";

	return 0;
}

