# The C++ Standard Template Library (STL)

The Standard Template Library(STL) is a set of C++ template classes to provide common programming data structures
and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators.
It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite
for working with STL

### STL has four components
Algorithms
Containers
Functions
Iterators

#### Algorithms
The header algorithm defines a collection of functions especially designed to be used on ranges of elements.
They act on containers and provide means for various operations for the contents of the containers.
* Algorithm
	* Soring
	* Searching
	* Important STL Algorithms
	* Useful Array algorithms
	* Partition Operations
* Numeric
	* valarray class

#### Containers
Containers or container classes store objects and data. There are in total seven standard "first-class" container classes
and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.

* Sequence Containers : Implement data structures which can be accessed in a sequential manner.
	* vector
	* list
	* deque
	* arrays
	* forward_list (introduced in C++11)
* Container Adaptors : provide a different interface for sequential containers
	* queue
	* priority_queue
	* stack
* Associative Containers : implement sorted data structures that can be quickly searched (0 (log n) complexity)
	* set
	* multiset
	* map
	* multimap
* Unordered Associative Containers : implement unordered data structures that can be quickly searched
	* unordered_set (introduced in C++11)
	* unordered_multiset (introduced in C++11)
	* unordered_map (introduced in C++11)
	* unordered_multimap (introduced in C++11)

	<img src="FlowchartOfAdaptiveContainersAndUnorderedContainers.png"></img><br/>
	<img src="FlowchartOfSequenceContainersAndOrderedContainers_2.png"></img>


#### Functions
The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors.
Functors allow the working of the associated function to be customized with the help of parameters to be passed.
* Functors

#### Iterators
As the name suggests, iterators are used for working upon a sequence of values. 
The are the major feature that allow generality in STL.
* Iterators

#### Utility Library
Defined in header <utility>
* pair


##### Sort in C++ STL
Soring is one of the most basic functions applied to data. It means arranging the data in a particular fashion, which can be
increasing or decreasing. There is a builtin function in C++ STL by the name of sort().
This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and
InsertionSort. By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than
N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.

```C++
sort(start_address, end_address)
start_address : the address of the first element of the array
end_address : the address of the next contiguous location of the last element of the array.
So actually sort() sorts in the range of [startaddress, endaddress]
```
01_sort.cpp

##### Binary Search in C++ STL
Binary search is a widely used searching algorithm that requires the array to be sorted before search is applied.
The main idea behind this algorithm is to keep dividing the array in half (divide and conquer) until the element is found,
or all the elements are exhausted.
It works by comparing the middle item of the array with our target, if it matches, it returns true otherwise if the middle term
is greater than the target, the search is performed in the left sub-array.
If the middle term is less than the target, the search is performed in the right sub-array.

The prototype for binary search is:
```C++
binary_search(start_address, end_address, valuetofind)
Parameters:
start_address : the address of the first element of the array
end_address : the address of the next contiguous location of the last element of the array.
valuetofind: the target value which we have to search for.

Returns:
true if an element equal to valuetofind is found, else false.
```
02_search.cpp

##### Non-Manipulating Algorithms
1. sort(first_iterator, last_iterator) - To sort the given vector
2. reverse(first_iterator, last_iterator) - To reverse a vector.
3. *max_element(first_iterator, last_iterator) - To find the maximum element of a vector
4. *min_element(first_iterator, last_iterator) - To find the maximum element of a vector
5. accumulate (firs_iterator, last_iterator, initial value of sum) - Does the summation of vector elements
6. count(first_iterator, last_iterator,x) - To count the occurrences of x in vector.
7. find(first_iterator, last_iterator, x) - Returns an iterator to the first occurence of x in vector 
and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
8. binary_search(first_iterator, last_iterator, x) - Tests whether x exists in sorted vector or not.
9. lower_bound(first_iterator, last_iterator, x) - returns an iterator pointing to the first element in the range [first, last) which has a value not less than 'x'.
10. upper_bound(first_iterator, last_iterator, x) - returns an iterator pointing to the first element in the range [first, last) which has a value greater than 'x'.

##### Some-Manipulating Algorithms
1. arr.erase(position to be deleted) - This erases selected element in vector and shifts and resizes the vector elements accordingly.
2. arr.erase(unique(arr.begin(), arr.end()), arr.end()) - This erases the duplicate occurrences in sorted vector in a single line.
3. next_permutation(first_iterator, last_iterator) - This modified the vector to tis next permutation.
4. prev_permutation(first_iterator, last_iterator) - This modified the vector to its previous permutation.
5. distance(first_iterator, desired_position) - It returns the distance of desired position from the first iterator. 
This function is very useful while finding the index.

##### Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and iota)
From c++11 onwards, some new and interesting algorithms are added in STL of C++. These algorithms operate on an array
and are useful in saving time during coding and hence useful in competitive programming as well.
1. all_of()
This function operates on whole range of array elements and can save time to run a loop to check each elements one by one.
It checks for a given property on every element and returns true when each element in range satisfies specified property, else returns false.
2. any_of()
This function checks for a given range if there's even one element satisfying a given property mentioned in function.
Return true if at least one element satisfies the property else returns false.
3. none_of()
This function returns true if none of elements statisfies the given condition else returns false.
4. copy_n()
copy_n() copies one array elements to new array. This type of copy creates a deep copy of array.
This function takes 3 arguments, source array name, size of array and the target array name.
5. iota()
This function is used to assign continuous values to array. 
This function accepts 3 arguments, the array name, size, and the starting number.

##### std:partition in C++ STL
C++ has a class in its STL algorithms library which allows us easy partition algorithms using certain inbuilt functions.
Partition refers to act of dividing elements of containers depending upon a given condition.
Partition operations:
1. partition(beg, end, condition) : This function is used to partition the elements on basis of condition mentioned in its arguments.
2. is_partitioned(beg, end, condition): This function returns boolean true if container is partitioned else returns false.
3. stable_partition(beg, end, condition) : This function is used to partition the elements on basis of condition mentioned
in its arguments in such a way that the relative order of the elements is preserved.
4. partition_point(beg, end, condition) : This function returns an iterator pointing to the partition point of container i.e.
the first element in the partitioned range [beg, end) for which condition is not true. The container should already be 
partitioned for this function to work.
5. partition_copy(beg, end, beg1, beg2, condition) : This function copies the partitioned elements in the different
containers mentioned in its arguments. It takes 5 arguments. Beginning and ending position of container, beginning
position of new container where elements have to be copied (elements returning true for condition), beginning position
of new container where other elements have to be copied (elements returning false for condition) and the conditon.
Resizing new containers is necessary for this function.

##### Reference
<https://www.geeksforgeeks.org/the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-c-stl/>

<https://www.geeksforgeeks.org/algorithms-library-c-stl/>

<https://www.geeksforgeeks.org/stdpartition-in-c-stl/>
