# Algorithm

## Definition

Definition from [GeeksforGeeks](https://www.geeksforgeeks.org/what-is-an-algorithm-definition-types-complexity-examples/?ref=lbp)  
> An algorithm is a well-defined sequential computational technique that accepts a value or a collection of values as input and outputs a value or output that is needed to solve a problem. Or we can say that an algorithm is said to be accurate if and only if it stops with the proper output for each input instance.

Defintions from [40 Algorithms Every Programmer Should Know](https://books.google.co.kr/books?id=4IzrDwAAQBAJ&printsec=frontcover&source=gbs_ge_summary_r&cad=0#v=onepage&q&f=false)  
> An algorithm is a finite set of unambiguous instructions that, given some set of initial conditions, can be performed in a prescribed sequence to achieve a certain goal and that has a recognizable set of end conditions

## Type
- Sorting algorithms
  - [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm): Wikipedia
  - [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/): GeeksforGeeks
- Search algorithms
  - [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm): Wikipedia
  - [Searching Algorithms](https://www.geeksforgeeks.org/searching-algorithms/): GeeksforGeeks
- Graph algorithms
  - [Graph theory / Algorithms](https://en.wikipedia.org/wiki/Graph_theory#Algorithms): Wikipedia
  - [Graph Data Structure And Algorithms](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/): GeeksforGeeks

## Numeric
- [accumulate](https://en.cppreference.com/w/cpp/algorithm/accumulate)
- [partial_sum](https://en.cppreference.com/w/cpp/algorithm/partial_sum)
- [inner_product](https://en.cppreference.com/w/cpp/algorithm/inner_product)
- [adjacent_difference](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference)
- [itoa](https://en.cppreference.com/w/cpp/algorithm/iota)

## Algorithm

### Non-modifing
- [all_of](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of)
- [any_of](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of)
- [none_of](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of)
- [for_each](https://en.cppreference.com/w/cpp/algorithm/for_each)
- [count](https://en.cppreference.com/w/cpp/algorithm/count)
- [count_if](https://en.cppreference.com/w/cpp/algorithm/count)
- [mismatch](https://en.cppreference.com/w/cpp/algorithm/mismatch)
- [find](https://en.cppreference.com/w/cpp/algorithm/find)
- [find_if](https://en.cppreference.com/w/cpp/algorithm/find)
- [find_if_not](https://en.cppreference.com/w/cpp/algorithm/find)
- [search](https://en.cppreference.com/w/cpp/algorithm/search)

### Modifying
- [copy](https://en.cppreference.com/w/cpp/algorithm/copy)
- [copy_if](https://en.cppreference.com/w/cpp/algorithm/copy)
- [copy_n](https://en.cppreference.com/w/cpp/algorithm/copy_n)
- [copy_backward](https://en.cppreference.com/w/cpp/algorithm/copy_backward)
- [fill](https://en.cppreference.com/w/cpp/algorithm/fill)
- [fill_n](https://en.cppreference.com/w/cpp/algorithm/fill_n)
- [move](https://en.cppreference.com/w/cpp/algorithm/move)
- [generate](https://en.cppreference.com/w/cpp/algorithm/generate)
- [transform](https://en.cppreference.com/w/cpp/algorithm/transform)
- [reverse](https://en.cppreference.com/w/cpp/algorithm/reverse)
- [rotate](https://en.cppreference.com/w/cpp/algorithm/rotate)
- [shuffle](https://en.cppreference.com/w/cpp/algorithm/random_shuffle)
- [remove](https://en.cppreference.com/w/cpp/algorithm/remove)
- [remove_if](https://en.cppreference.com/w/cpp/algorithm/remove)
- [unique](https://en.cppreference.com/w/cpp/algorithm/unique)

#### Search
- [lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
- [upper_bound](https://en.cppreference.com/w/cpp/algorithm/upper_bound)
- [binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search)
- [equal_range](https://en.cppreference.com/w/cpp/algorithm/equal_range)

### Partition
- [partition](https://en.cppreference.com/w/cpp/algorithm/partition)
- [is_partitioned](https://en.cppreference.com/w/cpp/algorithm/is_partitioned)
- [partition_copy](https://en.cppreference.com/w/cpp/algorithm/partition_copy)
- [stable_partition](https://en.cppreference.com/w/cpp/algorithm/stable_partition)
- [partition_point](https://en.cppreference.com/w/cpp/algorithm/partition_point)

### Sort
- [sort](https://en.cppreference.com/w/cpp/algorithm/sort)
- [is_sorted](https://en.cppreference.com/w/cpp/algorithm/is_sorted)
- [is_sorted_until](https://en.cppreference.com/w/cpp/algorithm/is_sorted_until)
- [partial_sort](https://en.cppreference.com/w/cpp/algorithm/partial_sort)
- [partial_sort_copy](https://en.cppreference.com/w/cpp/algorithm/partial_sort_copy)
- [stable_sort](https://en.cppreference.com/w/cpp/algorithm/stable_sort)
- [nth_element](https://en.cppreference.com/w/cpp/algorithm/nth_element)

### Heap
- [sort_heap](https://en.cppreference.com/w/cpp/algorithm/sort_heap)
- [pop_heap](https://en.cppreference.com/w/cpp/algorithm/pop_heap)
- [push_heap](https://en.cppreference.com/w/cpp/algorithm/push_heap)
- [make_heap](https://en.cppreference.com/w/cpp/algorithm/make_heap)
- [is_heap](https://en.cppreference.com/w/cpp/algorithm/is_heap)
- [is_heap_until](https://en.cppreference.com/w/cpp/algorithm/is_heap_until)

## Memory
- [uninitialized_copy](https://en.cppreference.com/w/cpp/memory/uninitialized_copy)
- [uninitialized_copy_n](https://en.cppreference.com/w/cpp/memory/uninitialized_copy_n)
- [uninitialized_fill](https://en.cppreference.com/w/cpp/memory/uninitialized_fill)
- [uninitialized_fill_n](https://en.cppreference.com/w/cpp/memory/uninitialized_fill_n)
- [uninitialized_move](https://en.cppreference.com/w/cpp/memory/uninitialized_move) (C++17)

# Complexity
## Time Complexity
_By Anant Patni_  
Time complexity is analyzed for very large input size and worst case scenario.  
From best, good, fair, bad, worst  
O(1) < O(log n) < O(n) < O(n log n) < O(n<sup>c</sup>) < O(n!)
<table>
  <tr>
    <td style="text-align:center">Algorithm</td><td colspan=3 style="text-align:center">Time Complexity</td>
  </tr>
  <tr>
    <td></td><td>Best</td><td>Average</td><td>Worst</td>
  </tr>
  <tr>
    <td>Selection Sort</td><td>Ω(n<sup>2</sup>)</td><td>Θ(n<sup>2</sup>)</td><td>O(n<sup>2</sup>)</td>
  </tr>
  <tr>
    <td>Bubble Sort</td><td>Ω(n)</td><td>Θ(n<sup>2</sup>)</td><td>O(n<sup>2</sup>)</td>
  </tr>
  <tr>
    <td>Insertion Sort</td><td>Ω(n)</td><td>Θ(n<sup>2</sup>)</td><td>O(n<sup>2</sup>)</td>
  </tr>
  <tr>
    <td>Heap Sort</td><td>Ω(n log n)</td><td>Θ(n log n)</td><td>O(n log n)</td>
  </tr>
  <tr>
    <td>Quick Sort</td><td>Ω(n log n)</td><td>Θ(n log n)</td><td>O(n<sup>2</sup>)</td>
  </tr>
  <tr>
    <td>Merge Sort</td><td>Ω(n log n)</td><td>Θ(n log n)</td><td>O(n log n)</td>
  </tr>
  <tr>
    <td>Bucket Sort</td><td>Ω(n+k)</td><td>Θ(n+k)</td><td>O(n<sup>2</sup>)</td>
  </tr>
  <tr>
    <td>Radix Sort</td><td>Ω(nk)</td><td>Θ(nk)</td><td>O(nk)</td>
  </tr>
</table>

## Space Complexity
Space complexity is amount of memory space used by an program or algorithm.

# C++
## C++ Core Guidelines
[P.13: Use support libraries as appropriate](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#p13-use-support-libraries-as-appropriate)  
[F.52: Prefer capturing by reference in lambdas that will be used locally, including passed to algorithms](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f52-prefer-capturing-by-reference-in-lambdas-that-will-be-used-locally-including-passed-to-algorithms)  
[ES.1: Prefer the standard library to other libraries and to “handcrafted code”](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es1-prefer-the-standard-library-to-other-libraries-and-to-handcrafted-code)  
[ES.3: Don’t repeat yourself, avoid redundant code](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es3-dont-repeat-yourself-avoid-redundant-code)  
[Per.7: Design to enable optimization](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#per7-design-to-enable-optimization)  
[T.2: Use templates to express algorithms that apply to many argument types](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#t2-use-templates-to-express-algorithms-that-apply-to-many-argument-types)  
[SL.1: Use libraries wherever possible](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#sl1--use-libraries-wherever-possible)

# Links
## Algoithms
- [Algorithm](https://en.wikipedia.org/wiki/Algorithm): Wikipedia
- [Algorithms](https://www.geeksforgeeks.org/fundamentals-of-algorithms): GeeksforGeeks
- [Binary heap](https://en.wikipedia.org/wiki/Binary_heap): Wikipedia
## Complexity
- [Computational complexity](https://en.wikipedia.org/wiki/Computational_complexity): Wikipedia
- [Time complexity](https://en.wikipedia.org/wiki/Time_complexity): Wikipedia
- [Calculating Time Complexity | New Examples | GeeksforGeeks](https://youtu.be/KXAbAa1mieU): By Anant Patni
## Logarithm
- [Logarithms by Don't Memorise](https://youtube.com/playlist?list=PLmdFyQYShrjcWl13fndjdWRBTF0C-tHG3): Playlist has 9 videos
## C++
- [Fluent C++](https://www.fluentcpp.com/): Jonathan Boccara's blog
  - [The World Map of C++ STL Algorithms](https://www.fluentcpp.com/getthemap/)
  - [105 STL Algorithms in Less Than an Hour - cppcon2018](https://youtu.be/2olsGf6JIkU)
- [Algorithms library](https://en.cppreference.com/w/cpp/algorithm): cppreference.com
- [\<algorithm\>](https://en.cppreference.com/w/cpp/header/algorithm): cppreference.com
- [\<numeric\>](https://en.cppreference.com/w/cpp/header/numeric): cppreference.com
- [\<algorithm\>](https://www.cplusplus.com/reference/algorithm/): cplusplus.com
- [\<numeric\>](https://www.cplusplus.com/reference/numeric/): cplusplus.com
- [Algorithms Articles](https://www.cplusplus.com/articles/algorithms/): cplusplus.com
