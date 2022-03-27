# C++ STL (a.k.a. Standard Template Library)
## Components
### Containers
  * Sequence containers
    * array: static contiguous array
    * vector: dynamic contiguous array
    * deque: double-ended queue
    * forward_list: singly-linked list
    * list: doubly-linked list
  * Associative containers
    * set: collection of unique keys, sorted by keys
    * map: collection of key-value pairs, sorted by keys, keys are unique
    * multiset: collection of keys, sorted by keys
    * multimap: collection of key-value pairs, sorted by keys
  * Container adaptors
    * stack: adapts a container to provide stack (LIFO data structure)
    * queue: adapts a container to provide queue (FIFO data structure)
    * priority_queue: adapts a container to provide priority queue
### Iterators
### Functions
### Algorithms
There is large number of algorithms provided by STL (well over 100)
* Non-modifying sequence operations
  * all_of / any_of / none_of: checks if a predicate is true for all, any or none of the elements in a range
  * for_each: applies a function to a range of elements
  * count / count_if: returns the number of elements satisfying specific criteria
  * mismatch: finds the first position where two ranges differ
  * find / find_if / find_if_not: finds the first element satisfying specific criteria
  * find_end: finds the last sequence of elements in a certain range
  * search: searches for a range of elements
  * ...
* Modifying sequence operations
  * copy / copy_if: copies a range of elements to a new location
  * copy_n: copies a number of elements to a new location
  * copy_backward: copies a range of elements in backwards order
  * move: moves a range of elements to a new location
  * move_backward: moves a range of elements to a new location in backwards order
  * ...
* Partitioning operations
  * is_partitioned: determines if the range is partitioned by the given predicate
  * partition: divides a range of elements into two groups
  * partition_copy: copies a range dividing the elements into two groups
  * partition_point: locates the partition point of a partitioned range
  * ...
* Sorting operations
  * is_sorted: checks whether a range is sorted into ascending order
  * is_sorted_until: finds the largest sorted subrange
  * sort: sorts a range into ascending order
  * partial_sort_copy: copies and partially sorts a range of elements
  * ...
* Binary search operations (on sorted ranges)
* Other operations on sorted ranges
* Set operations (on sorted ranges)
* Heap operations
* Minimum/maximum operations
* Comparison operations
* Permutation operations
* Numeric operations
* Operations on uninitialized memory
* C library
### Utilities
* Pairs and tuples
  * tuple: implements fixed size container, which holds elements of possibly different types
  * tuple_size: obtains the number of elements of a tuple-like type
  * tuple_element: obtains the element types of a tuple-like type
  * ...

### Reference
[[1] C++ reference. 2022. Containers library.](https://en.cppreference.com/w/cpp/container) <br>
[[2] C++ reference. 2022. Iterator library.](https://en.cppreference.com/w/cpp/iterator) <br>
[[3] C++ reference. 2022. std::function.](https://en.cppreference.com/w/cpp/utility/functional/function) <br>
[[4] C++ reference. 2022. Algorithms library.](https://en.cppreference.com/w/cpp/algorithm) <br>
[[5] Bob Steagall. 2021. Back to Basics: Classic STL. Video. CppCon.](https://youtu.be/tXUXl_RzkAk) <br>
[[6] Standard C++ Foundation. 2022. C++11 Standard Library Extensions - Containers and Algorithms. ISOCPP.ORG.](https://isocpp.org/wiki/faq/cpp11-library-stl) <br>
[[7] GeeksforGeeks. 2022. The C++ Standard Template Library (STL).](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=gcse)