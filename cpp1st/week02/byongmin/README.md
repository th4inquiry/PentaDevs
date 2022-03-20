# Template

## Contents

- Definition
- Defining and using templates
- Template parameters and template arguments
- Function templates
- Class templates
- Template Specialization and Instantiation (implicit, explicit)
- Explicuit (full) specialization
- Partial specialization
- Variable templates (c++14)
- Type alias, alias template (c++11)
- Template argument deduction
- Introduce CRTP (Curiously recurring template pattern)
- Design Pattern using Tempalte

### Definition

- Templates are a feature of the C++ programming language that allows functions and classes to operate with generic types. This allows a function or class to work on many different data types without being rewritten for each one. - *[Template (C++) in Wikipedia](https://en.wikipedia.org/wiki/Template_\(C%2B%2B\))*
- A template is a construct that generates an ordinary type or function at compile time based on arguments the user supplies for the template parameters. - *[Templates (C++) in MSDN](https://docs.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170#defining-and-using-templates)*

### Defining and using templates

## study source

- (web) msdn
- (web) cppreference
- (pdf) standard docuemnt
- (book) cook book
- (book) 전문가를 위한 C++
- (book) Effective Modern C++

## cppreference

<https://en.cppreference.com/w/cpp/language/templates>

- Template parameters and template arguments
- Class templates
- Function templates
- Type alias, alias template (c++11)
- Variable templates (c++14)
- Template argument deduction
- Class template argument deduction (c++17)
- Explicuit (full) specialization
- Partial specialization
- Dependent Names (c++11)
  - sizeof ...
  - Fold-expressions
- SFINAE (metaprogramming)
- Constraints and concepts (c++20)

## msdn template c++

<https://docs.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170>

- typename
- Class templates
- Function templates
- Template specialization
- Templates and name resolution
- Source code organization (C++ templates)

## cplusplus.com

<https://www.cplusplus.com/doc/oldtutorial/templates/>

- Function templates
- Class templates
- Template specialization
- Non-type parameters for templates
- Templates and multiple-file projects
  - template class를 정의할 때, 반드시 header에 구현 코드르 넣어야 하는 제약을 우회하는 방법

## other keyword

- Template type deduction
- [Template Instantiation](https://www.ibm.com/docs/en/i/7.3?topic=only-template-instantiation-c)
- [Template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming)

## design pattern

- [Modern C++ Singleton Template](https://codereview.stackexchange.com/questions/173929/modern-c-singleton-template)
- [CRTP (Curiously recurring template pattern)](https://en.cppreference.com/w/cpp/language/crtp)

## reference

- [Youtube CppCon, Back to Basics : Templates (part 1 of 2)](https://youtu.be/XN319NYEOcE)
- [Youtube CppCon, Back to Basics : Templates (part 2 of 2)](https://youtu.be/2Y9XbltAfXs)
- [MORDERNES C++](https://www.modernescpp.com/index.php/template-instantiation)

## examples

- Simple tempalte
- Kinds of Template
  - class template
  - function template
  - member function template
  - alias template
  - variable template
  - lambda template
- Template parameters and template arguments
- Instantiation and Specialization
  - Implicit Instantiation
  - Explicit Instantiation
  - Explicit (full) specialization
  - Partial specialization
- Practical examples
  - Templates and multiple-file projects
  - Introduce CRTP (Curiously recurring template pattern)
  - Design Pattern using Tempalte
- Template type deduction
  