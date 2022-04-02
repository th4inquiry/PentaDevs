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

##### std:valarray in C++ STL
C++98 introduced a special container valarray to hold and provide mathematical operations on arrays efficiently.
* It supports element-wise mathematical operations and various forms of generalized subscript operators, slicing and indirect access.
* As compare to vectors, valarrays are efficient in certain mathematical operations than vectors also.
Public member functions in valarray class:
1. apply() : This function applies the manipulation given in its arguments to all the valarray elements at once 
and returns a new valarray with manipulated values.
2. sum() : This function returns the summation of all the elements of valarrays at once.
3. min() : This function returns the smallest element of valarray.
4. max() : This function returns the largest element of valarray.
5. shift() : This function returns the new valarray after shifting elements by the number mentioned in its argument.
If the number is positive, left-shift is applied, if number is negative, right-shift is applied.
6.cshift() : This function returns the new valarray after circularly shifting(rotating) elements by the number mentioned in its argument.
If the number is positive, left-circular shift is applied, if number is negative, right-circular shift is applied.
7. swap() : This function swaps one valarray with other.

##### Vector in C++ STL
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that
they can be accessed and traverse using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time,
as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no
resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

Iterators
1. begin() : Returns an iterator pointing to the first element in the vector
2. end() : Returns an iterator pointing to the theoretical element that follows that last element in the vector
3. rbegin() : Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
4. rend() : Returns a reverse iterator pointing to the theretical element preceding the first element in the vector (considered as reverse end)
5. cbegin() : Returns a constant iterator pointing to the first element in the vector.
6. cend() : Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
7. crbegin() : Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
8. crend() : Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

Capacity
1. size() : Returns the number of elements in the vector
2. max_size() : Returns the maximum number of elements that the vector can hold.
3. capacity() : Returns the size of the storage space currently allocated to the vector expressed as number of elements.
4. resize(n) : Resizes the container so that it contains 'n' elements.
5. empty() : Returns whether the container is empty.
6. shrink_to_fit() : Reduces the capacity of the container to fit its size and destroys all element beyond the capacity.
7. reverse() : Requests that the vector capacity be at least enough to contain n elements.

Elements access
1. reference operator [g] : Returns a reference to the element at position 'g' in the vector
2. at(g) : Returns a reference to the element at position 'g' in the vector
3. front() : Returns a reference to the first element in the vector
4. back() : Returns a reference to the last element in the vector
5. data() : Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

Modifiers
1. assign() : It assigns new value to the vector elements by replacing old ones
2. push_back() : It push the elements into a vector from the back
3. pop_back() : It is used to pop or remove elements from a vector from the back
4. insert() : It inserts new elements before the element at the specified position
5. erase() : It is used to remove elements from a container from the specified position or range.
6. swap() : It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
7. clear() : It is used to remove all the elements of the vector container
8. emplace() : It extends the container by inserting new element at position
9. emplace_back() : It is used to insert a new element into the vector container, the new element is added to the end of the vector

##### List in C++ STL
Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, the list has slow traversal, but once
a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about a doubly linked list.
For implementing a singly linked list, we use a forward list. Below is the program to show the working of some functions of List:

front() : Returns the value of the first element in the list.
back() : Returns the value of the last element in the list.
push_front(g) : Adds a new element 'g' at the beginning of the list.
push_back(g) : Adds a new element 'g' at the end of the list.
pop_front() : Removes the first element of the list, and reduces size of the list by 1.
pop_back() : Removes the last element of the list, and reduces size of the list by 1.
list::begin() : begin() function returns an iterator pointing to the first element of the list.
list::end() : end() function returns an iterator pointing to the theoretical last element which follows the last element.


##### Reference
<https://www.geeksforgeeks.org/the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/>

<https://www.geeksforgeeks.org/sort-c-stl/>

<https://www.geeksforgeeks.org/algorithms-library-c-stl/>

<https://www.geeksforgeeks.org/stdpartition-in-c-stl/>

<https://www.geeksforgeeks.org/std-valarray-class-c/>
