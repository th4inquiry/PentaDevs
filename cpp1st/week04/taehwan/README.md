# Smart Pointer
Smart pointers enable automatic, exception-safe, object lifetime management. Defined in header ```<memory>```.

## RAII
Resource acquisition is initialization (RAII) is a programming idiom used in several object-oriented, statically-typed 
programming languages to describe a particular language behavior. In RAII, holding a resource is a class invariant, and 
is tied to object lifetime. Resource allocation (or acquisition) is done during object creation (specifically 
initialization), by the constructor, while resource de-allocation (release) is done during object destruction 
(specifically finalization), by the destructor. In other words, resource acquisition must succeed for initialization to 
succeed. Thus, the resource is guaranteed to be held between when initialization finished and finalization starts 
(holding the resource is a class invariant), and to be held only when the object is alive. Thus, if there are no object 
leaks, there are no resource leaks. <br>
RAII is associated most prominently with c++ where it originated, but also D, Ada, Vala, and Rust. The technique was
developed for exception-safe resource management in C++ during 1984-89, primarily by Bjarne Stroustrup and Andrew Koenig, 
and the term itself was coined by Stroustrup. RAII is generally pronounced as an initialism, sometimes pronounced as
"R, A, double I". <br>
Other names for this idiom include _Constructor Acquires, Destructor Releases_ (CADre) and one particular style of use is 
called _Scope-based Resource Management_ (SBRM). This latter term is for the special case of automatic variables. RAII
ties resources to object _lifetime_, which may not coincide with entry and exit of a scope. (Notably variables allocated
on the free store have lifetimes unrelated to any given scope.) However, using RAII for automatic variables (ABRM) is
the most common use case.

## Pointer categories
* unique_ptr (C++11): smart pointer with unique object ownership semantics
* shared_ptr (C++11): smart pointer with shared object ownership semantics
* weak_ptr (C++11): weak reference to an object managed by ```std:shared_ptr```
* auto_ptr (deprecated in C++11, removed in C++17): smart pointer with strict object ownership semantics

## Helper classes
* owner_less (C++11): provides mixed-type owner-based ordering of shared and weak pointers
* enable_shared_from_this (C++11): allows an object to create a shared_ptr referring to itself
* bad_weak_ptr (C++11): exception thrown when accessing a weak_ptr which refers to already destroyed object
* default_delete (C++11): default deleter for unique_ptr

### Reference
[[1] C++ reference. 2022. Dynamic memory management.](https://en.cppreference.com/w/cpp/memory) <br>
[[2] Wikipedia. 2022. Resource acquisition is initialization.](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) <br>
[[3] GeeksforGeeks. 2022. Smart Pointers in C++ and How to Use Them.](https://www.geeksforgeeks.org/smart-pointers-cpp/) <br>
[[4] Mike Shah. 2021. Back to Basics: Pointer. Video. CppCon.](https://youtu.be/0zd8eznWv4k) <br>
[[5] Inbal Levi. 2021. Back to Basic: Smart Pointers and RAII. Video. CppCon.](https://youtu.be/07rJOzFRs6M) <br>