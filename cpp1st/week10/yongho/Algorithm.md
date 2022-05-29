
### Algorithms library

The algorithms library defines functions for a variety of purpose (e.g. searching, sorting, counting, manipulating) that operate on ranges of elements.

Note that a range is defined as [first, last) where last refers to the element past the last element to inspect or modify.


#### Constrained algorithms

C++20 provides constrained version of most algorithms in the namespace std::ranges.
In these algorithms, a range can be specified as either an iterator-sentinel pair or as a single range argument, and projections and
pointer-to-member callables are supported. Additionally, the return types of most algorithm have been changed to return all potentially
useful information computed during the execution of the algorithm. 

```C++
std::vector<int> v = {7, 1, 4, 0, -1};
std::ranges::sort(v); //constrained algorithm
```

#### Execution policies

Most algorithms have overloads that accept execution policies. The standard library algorithms support several exectution policies, and the library
provides corresponding execution policy types and objects. Users may select an execution policy statically by invoking a parallel algorithm
with an execution policy object of the corresponding type.
Standard library implementations (but not the users) may define additional execution policies as an extension.
The semantics of parallel algorithms invoked with an execution policy object of implementation-defined type is implementation-defined.
Parallel version of algorithms (except for std::for_each and std::for_each_n) are allowed to make arbitrary copies of elements from ranges, as long as both
```std::is_trivially_copy_constructible_v<T>``` and ```std::is_trivially_destructible_v<T>``` are true, where T is the type of elements.

| Defined in header<execution> <br> Defined in namespace std::execution	 |  |
| :--: | :--: |
| sequenced_policy (C++17)	|  |
| parallel_policy (C++17) | execution policy types |
| parallel_unsequenced_policy (C++17) | (class)	|
| unsequenced_policy (C++20) | |
| :--: | :--: |
| seq (C++17)	|  |
| par (C++17) | global execution policy objects |
| par_unseq (C++17) | (constant) |
| unseq (C++20) | |

| Defined in namespace std |  |
| :--: | :--: |
| is_execution_policy (C++17)	| test whether a class represents an execution policy |

Feature testing macro: __cpp_lib_parallel_algorithm (for parallel version of algorithms).
Feature testing macro: __cpp_lib_parallel_execution (for execution policies)

#### Non-modifying sequence operations

| Defined in header<algorithm> |  |
| :--: | :--: |
| sequenced_policy (C++17)	|  |
| parallel_policy (C++17) | execution policy types |
| parallel_unsequenced_policy (C++17) | (class)	|
| unsequenced_policy (C++20) | |


### Reference

https://en.cppreference.com/w/cpp/algorithm

https://www.cplusplus.com/reference/algorithm/