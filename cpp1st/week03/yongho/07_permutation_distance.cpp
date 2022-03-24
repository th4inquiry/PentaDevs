#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int arr[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vect(arr, arr + n);

	std::cout << "Given Vector is:\n";
	for (int i = 0; i < n; i++)
		std::cout << vect[i] << " ";

	std::next_permutation(vect.begin(), vect.end());

	std::cout << "\n\nVector after performing next permutation:\n";
	for (int i = 0; i < n; i++)
		std::cout << vect[i] << " ";

	std::prev_permutation(vect.begin(), vect.end());

	std::cout << "\n\nVector after performing prev permutation:\n";
	for (int i = 0; i < n; i++)
		std::cout << vect[i] << " ";

	//Return distance of first to maximum element
	std::cout << "\n\nDistance between first to max element: ";
	std::cout << std::distance(vect.begin(), std::max_element(vect.begin(), vect.end()));
	return 0;
}
