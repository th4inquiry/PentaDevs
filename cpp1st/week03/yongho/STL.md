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


##### Reference
<https://www.geeksforgeeks.org/the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-c-stl/>

<https://www.geeksforgeeks.org/algorithms-library-c-stl/>
