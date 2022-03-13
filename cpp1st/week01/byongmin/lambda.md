# Lambda

## Lambda Basic Knowledge

- Functional Programming
  - 함수를 변수처럼 사용한다.

- Functor
  - A functor (or function object) is a C++ class that acts like a function. Implement the operator() to crate functor.

- Closure
  - 내부함수에서 외부함수의 변수에 접근할 수 있는 테크닉을 말한다.
  - C++에서는 lambda의 instance화 된 것을 말하기도 한다.
    - Lamba vs. Closure == Class vs. Object

- Lambda expression
  - Constructs a closure: an unnamed function object capable of capturing variables in scope.

- Basic Syntax
  - [ **captures** ] ( **params** ) -> **return_type** { **body** }
  - Captures
    - Capture by value
    - Capture by reference
    - Capture by this

## Examples

- functionObject_Lambda.cpp
  - Compare function object vs. lambda expression
- lambdaExpression1.cpp
  - How to use lambda expression

## Reference

- MSDN
  - *[Lambda expressions in C++](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)*
  - *[Lambda Expression syntax](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expression-syntax?view=msvc-170)*
  - *[Examples of Lambda Expressions](https://docs.microsoft.com/en-us/cpp/cpp/examples-of-lambda-expressions?view=msvc-170>)*
  - *[constexpr lambda expressions in C++](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-constexpr?view=msvc-170)*

- lambda vs. closure
  - *[lambda vs. closure](<http://scottmeyers.blogspot.com/2013/05/lambdas-vs-closures.html>)*

- Markdown Syntax
  - *[Markdown Syntax](https://www.markdownguide.org/basic-syntax)*
