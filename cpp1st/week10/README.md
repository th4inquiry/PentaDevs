# C++ algorithm
## Components

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

### Reference
[[1] C++ reference. 2022. Algorithms library.](https://en.cppreference.com/w/cpp/algorithm) <br>
[[2] Standard C++ Foundation. 2022. C++11 Standard Library Extensions - Containers and Algorithms. ISOCPP.ORG.](https://isocpp.org/wiki/faq/cpp11-library-stl) <br>