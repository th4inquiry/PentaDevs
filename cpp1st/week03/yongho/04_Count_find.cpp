#include <iostream>
#include <vector>

int main()
{
	//Initializing vector with array values
	int arr[] = { 10, 20,5,23,42,20,15, 100, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vect(arr, arr + n);

	std::cout << "Occurrences of 20 in vector : ";

	//Counts the occurrences of 20 from 1st to last element
	std::cout << std::count(vect.begin(), vect.end(), 20);

	//fin() returns iterator to last address if element not present
	find(vect.begin(), vect.end(), 99) != vect.end() ?
		std::cout << "\nElement found" :
		std::cout << "\nElement not found";

	return 0;
}