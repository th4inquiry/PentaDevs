# Exception

Exceptions are a mechanism for a piece of code to notify another piece of code of an “exceptional” situation or error condition without progressing through the normal code paths.

There are several specific advantages of exceptions over the ad hoc approaches in C and C++.

- When return codes are used as an error reporting mechanism, you might forget to check the return code and properly handle it either locally or by propagating it upward.
- When integer return codes are used, they generally do not contain sufficient information. Exceptions can be used to communicate information other than errors.
- Exception handling can skip levels of the call stack.

## Throwing and Catching Exceptions

```cpp
try {
 // ... code which may result in an exception being thrown
} catch (exception-type1 exception-name) {
 // ... code which responds to the exception of type 1
} catch (exception-type2 exception-name) {
 // ... code which responds to the exception of type 2
}
// ... remaining code
```

## Design for exception safety

### Basic techniques

A robust exception-handling policy requires careful thought and should be part of the design process.

- Lower layers
  - In general, most exceptions are detected and thrown
- Middle layers
  - In many cases, the correct behavior in the middle layers is to let an exception propagate up the call stack. A function should catch and "swallow" an exception only if it is able to completely recover from it.
- Highest layer
  - It might be appropriate to let an unhandled exception terminate a program if the exception leaves the program in a state in which its correctness cannot be guaranteed.

Keep resource classes simple and Use the RAII idiom to manage resources

### The three exception guarantees

- No-fail guarantee
  - the strongest guarantee that a function can provide. It states that the function will not throw an exception or allow one to propagate
- Strong guarantee
  - A function that provides a strong guarantee is essentially a transaction that has commit or rollback semantics: either it completely succeeds or it has no effect.
- Basic guarantee
  - The basic guarantee states that if an exception occurs, no memory is leaked and the object is still in a usable state even though the data might have been modified.

### Exception-safe classes

Follow these guidelines for any user-defined type that must be exception-safe

- Use smart pointers or other RAII-type wrappers to manage all resources
- Understand that an exception thrown in a base class constructor cannot be swallowed in a derived class constructor
- Consider whether to store all class state in a data member that is wrapped in a smart pointer, especially if a class has a concept of "initialization that is permitted to fail."
- Do not allow any exceptions to escape from a destructor. A basic axiom of C++ is that destructors should never allow an exception to propagate up the call stack

## Reference

- Professional C++ (4th Edition)
- [Exception handling in MSVC](https://docs.microsoft.com/en-us/cpp/cpp/exception-handling-in-visual-cpp?view=msvc-170)
