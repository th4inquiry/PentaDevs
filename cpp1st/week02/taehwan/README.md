# Templates<sup id="a1">[*](#1)</sup>
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

<b id="1">*</b> Reference: https://en.cppreference.com/w/cpp/language/templates