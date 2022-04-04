
# Smart Pointer

## OverView

Smart pointers automatically manage the lifetime of its resource.

* Class template
* Allocate and deallocate their resource in the constructor and destuctor according to the RAII Idiom. (Resource Acquisition Is Initialization)
* Support automatic memory management with reference counting
* Are C++ answer to garbage collection
* Release the resource if the smart pointer goes out of scope

* In C++ we allocate memory on the heap explicitly
* There is no inherent mechnism to verify "clean exit"
* Smart pointers create ownership for the allocated memory
* Smart pointers are provided in the <memory> header
* Smart pointers help to bridge the gap between:
    * Manually managed memory
    * Automatically managed memory

| Name	 | C++ Standard	 | Description	 |
| :--: | :--: | :-- |
| std::auto_ptr<br>(Stop)	 | C++98	 | * Owns the resource exclusively<br>* "Moves" its resource during a copy operation	 |
| std::unique_ptr	 | C++11	 | * Owns the resource exclusively<br>* Can not copied<br>* Deals with non-copy objects	 |
| std::shared_ptr	 | C++11	 | * Shares a resource<br>* Supports an reference counter to the shared resource and manages it<br>* Deletes the resource if the reference counter becomes 0	 |
| std::weak_ptr	 | C++11	 | * Borrows the resource<br>* Helps to break cyclic references<br>* Doesn't change the reference counter	 |


### What does 'OwnerShip' mean?

* Ownership usually refers to the management of objects' memory and lifetime
* Ownership leves:
    1. Value level
    2. Indirection (pointer) level
    3. Proxy (wrapper) level
* Consiser ownership with an extended definition:
    1. Memory
    2. Value
* The owner of and object can:
    1. Update the data
    2. Invalidate or Move the data
    3. Free the memory (erase)
* Each ability has a different effect on the program (and on its logic)

### <b>std::unique_ptr</b>

The 'std::unique_ptr' <b>exclusively manages</b> the lifetime of its resource

* Is the replacement for the deprecated Smart Pointers 'std::auto_ptr'
    'std::unique_ptr' doesn't support copy semantic
* Can be used in the containers and algorithms of the STL
    Containers and algorithms can not use copy semantic
* Has no overhead in space and time compared to a raw pointer
* Can be parameterized with a 'deleter:std::unique_ptr<T, Deleter>'
* Can be specialized for arrays 'std::unique_ptr<T[]>'

```C++
//Defined in header <memory>
template<class T, class Deleter=std::default_deleter<T>>
class unique_ptr;

template<class T, class Deleter>
class unique_ptr<T[]. Deleter>;
```

| **Function**	 | **Description**	 |
| :--: | :-- |
| uniq.release()	 | Returns a pointer to the managed object and releases the ownership	 |
| uniq.reset(ptr)	 | * Resets the resource to a new one<br>* Deletes the old resource	 |
| uniq.swap(ptr)	 | swaps the managed objects	 |
| uniq.get()	 | Returns a pointer to the managed object	 |
| uniq.get_deleter()	 | Returns the deleter that is used for destruction of the managed object	 |
| std::make_unique(....)	 | Creates the resource and wraps it in a <br>std::unie_ptr	 |


### <b>std::shared_ptr</b>

The 'std::shared_ptr' <b>shares a resource and manages</b> its lifetime

* Has a reference to the resource and the reference counter
    * Can have a given deleter
        shared_ptr<int> shPtr(new int, Del());
* The acces to the control block of the 'std::shared_ptr' is thread-safe
* "Will the last person out of the room please turn out the lights"

```C++
//Defined in header <memory>
template<class T>
class shared_ptr;
```

| **Function**	 | **Description**	 |
| :--: | :-- |
| sha.reset(ptr)	 | * Resets the management object<br>* Deletes eventually the management object	 |
| sha.swap(ptr)	 | * swaps the management object	 |
| sha.get()	 | Returns a stored pointer	 |
| sha.use_count()	 | Returns the number of shared_ptr objects referring to the same managed object |
| sha.unique()	 | Checks whether the managed object is managed only by the current shared_ptr instance	 |
| sha.get_deleter()	 | Returns the deleter	 |
| std::make_shared(...)	 | Creates the resource and wraps it in a<br>std::shared_ptr	 |


### <b>std::weak_ptr</b>

The 'std::weak_ptr' <b>is not a classic smart pointer</b>

* Owns no resource
* Brrows the resource from a 'std::shared_ptr'
* Can not access the resource
* Can create a 'std::shared_ptr' to the resource
* 'std::shared_ptr' needed in order to access the referenced object

The 'std::weak_ptr' doesn't change the reference counter
    Helps to break cycles of 'std::shared_ptr'

```C++
//Defined in header <memory>
template<class T>
class weak_ptr;
```

| **Function**	 | **Description**	 |
| :--: | :-- |
| wea.reset()	 | releases the owenership of the managed object	 |
| wea.swap(ptr)	 | swaps the managed objects	 |
| wea.expired()	 | Checks if the resource exists	 |
| wea.use_count()	 | Returns the number of shared_ptr objects that manage the object	 |
| wea.lock()	 | Creats a 'std::shared_ptr' that manages the referenced object	 |


#### Cyclic References

Classic Problem
    * If 'std::shared_ptr' builds a cycle, no 'std::shared_ptr' will be deleted automatically
Rescure
    * 'std::weak_ptr' breaks the cycle

#### Performance Comparison

Performance.cpp

#### Concurrency

The management of the control block of a 'std::shared_ptr' is thread-safe but not the access to the shared resource.

To share ownership between unrelated threads use a 'std::shared_ptr'

'std::shared_ptr' contracdiction in modern C++.

Use smart pointers but don't share
    > Forget what you learned in Kindergarten. Stop sharing. (Tony van Eerd)

Solution:
* C++11 : Atomic operations for 'std::shared_ptr'
* C++20 : Atomic shared pointers and partial specialization
    * std::atomic_shared_ptr -> std::atomic<std::shared_ptr<T>>
    * std::atomic_weak_ptr ->  std::atomic<std::weak_ptr<T>>

#### Function signature and ownership

| **Function Signature**	 | **Ownership Semactic**	 |
| :--: | :-- |
| func(value)	 | * Is an independent owner of resource<br>* Deleters the resource automatically at the end of func	 |
| func(pointer*)	 | * Brrows the resource<br>* The resource could be empty<br>* Must not delete the resource	 |
| func(reference)	 | * Borrows the resource<br>* Thre resource could not be empty<br>* Must not delete the resource	 |
| func(std::unique_ptr)	 | * Is an independent owner of the resouce<br>* Deletes the resource automatically at the end of func	 |
| func(shared_ptr)	 | * Is a shared owner of the resource<br>* May delete the resource at the end of func	 |

#### Smart Pointer as Parameter

| **Function Signature**	 | **Semactic**	 |
| :--: | :-- |
| func(std::unique_ptr<int>)	 | func <b>takes ownership</b>	 |
| func(std::unique_ptr<int>&)	 | func <b>might reseat</b> int 	 |
| func(std::shared_ptr<int>)	 | func <b>shares ownership</b>	 |
| func(std::shared_ptr<int>&)	 | func <b>might reseat</b> int 	 |
| func(const std::shared_ptr<int>&)	 | func <b>might retain a reference counter</b>	 |


# Memory Management



#### References

CppReference : smart pointers
<https://en.cppreference.com/book/intro/smart_pointers>
<https://en.cppreference.com/w/cpp/memory/unique_ptr>
<https://en.cppreference.com/w/cpp/memory/shared_ptr>
<https://en.cppreference.com/w/cpp/memory/weak_ptr>

Cplusplus : 
<https://www.cplusplus.com/reference/memory/>
<https://www.cplusplus.com/reference/memory/shared_ptr/>

Microsoft : Smart pointers (Modern c++) 
<https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170>

WikiPedia : Smart pointer
<https://en.wikipedia.org/wiki/Smart_pointer>

GeeksforGeeks : Smart Pointers in C++ and How to Use Then
<https://www.geeksforgeeks.org/smart-pointers-cpp/>

Youtube : CppCon 2019: Arthur O'Dwyer “Back to Basics: Smart Pointers”
<https://www.youtube.com/watch?v=xGDLkt-jBJ4>

Youtube : Back to Basics: Smart Pointers - Rainer Grimm - CppCon 2020
<https://www.youtube.com/watch?v=sQCSX7vmmKY>

Youtube : Back to Basics: Smart Pointers and RAII - Inbal Levi - CppCon 2021
<https://www.youtube.com/watch?v=07rJOzFRs6M>


simplilearn : All You Need to Know About C++ Memory Management
<https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-memory-management>

IsoCpp : Memory Management F&Q
<https://isocpp.org/wiki/faq/freestore-mgmt>

Dynamic memory management
<https://en.cppreference.com/w/cpp/memory>

CppReference : C++ history
<https://en.cppreference.com/w/cpp/language/history>

CppReference : value_initialization
<https://en.cppreference.com/w/cpp/language/value_initialization>

ModernCpp : initialization
<https://www.modernescpp.com/index.php/initialization>

CppReference : RAII
<https://en.cppreference.com/w/cpp/language/raii>
