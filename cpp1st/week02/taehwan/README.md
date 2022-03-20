# Templates
## Template classification
* Class template: a family of classes
* Function template: a family of functions
* Alias template: an alias to a family of types (since C++11)
* Variable template: a family of variables (since C++14)
* Constraints and concepts: a concept (since C++20)

## Template parameters
* Type template parameters
* Non-type template parameters
* template template parameters

### Syntax
* **template** < _parameter-list_ > _requires-clause_(optional) _declaration_
* **export** **template** < _parameter-list_ > _declaration_
* **template** < _parameter-list_ > **concept** _concept-name_ **=** _constraint-expression_ **;**

### template-id
* _template-name_ < _parameter-list_ >

### Reference
[[1] C++ reference. 2022. Templates](https://en.cppreference.com/w/cpp/language/templates) <br>
[[2] Bob Steagall. 2021. Back to Basics: Templates (part 1 of 2). Video. CppCon.](https://youtu.be/XN319NYEOcE) <br>
[[3] Bob Steagall. 2021. Back to Basics: Templates (part 2 of 2). Video. CppCon.](https://youtu.be/2Y9XbltAfXs) <br>
[[4] Dan Saks. 2019. Back to Basics: Function and Class Templates. Video. CppCon.](https://youtu.be/LMP_sxOaz6g) <br>
[[5] Bjarne Stroustrup. 2000. Wrapping C++ Member Function Calls. The C++ Report.](https://stroustrup.com/wrapper.pdf)