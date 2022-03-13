# Lambda Expression

## What is it?  
 A ***lambda expression***, sometimes also referred to as a lambda function or (strictly speaking incorrectly, but colloquially) as a lambda, is a simplified notation for defining and using an **anonymous function object**.<br>
+ The syntax is easier
+ Make the code more compact and easier to read
+ Very useful to define small callback
<br></br>
---
## General form of lambda expression (C++20)

```cpp
[capture_block] <template_params> (parameters) mutable constexpr 
    noexcept_specifier attributes 
    -> return_type { body }
```
#### Simple example
```cpp
    auto simpleLambda = []{ cout << "Hello simple lambda" << endl; };
    basicLambda();

    auto parametersLambda {
        [](int value){ cout << "The value is " << value << endl; } };
    parametersLambda(42);
```

+ ***capture block*** : 스코프에 있는 변수를 캡쳐하는 방식을 저장하고, lambda expression의 body에서 그 변수에 접근 가능<br></br>
+ ***template parameters*** (C++20) : template lambda expression 사용<br></br>
+ ***parameters*** : lambda expression 에 대한 매개변수 목록. 매개변수를 받지 않고 mutable, constexpr, noexcept 지정자, attributes, return type 을 지정하지 않는다면 생략 가능<br></br>
+ ***mutable*** : lambda expression을 mutable 로 지정<br></br>
+ ***constexpr*** : 컴파일 타임에 evaluation 된다. 생략하더라도, lambda expression 이 일정한 요건을 충족하면 내부적으로 constexpr 로 처리<br></br>
+ ***noexcept*** : noexcept 로 지정가능하며, 일반 함수에 대한 noexcept 와 동일<br></br>
+ ***attributes*** : 속성을 지정<br></br>
+ ***return type*** : return type 지정. 생략하면 컴파일러가 추론한다. 일반 함수의 리턴 타입 추론과 동일<br></br>
+ ***Requires clause*** (C++20) : lambda closure의 function call operator 에 대한 template type 제한을 추가<br></br>

---
## Various combinations for lambda captures semantics
|Lambda  | Description |
|--------|-------------|
|\[\](){}  | Does not capture anything|
|\[&](){} |Captures everything by reference.
|\[=](){} |Captures everything by copy. Implicit capturing of the pointer this
is deprecated in C++20.
|\[&x](){} |Capture only x by reference.
|\[x](){} |Capture only x by copy.
|\[&x...](){} |Capture pack extension x by reference.
|\[x...](){} |Capture pack extension x by copy.
|\[&, x](){} |Captures everything by reference except for x that is captured by copy.
|\[=, &x](){} |Captures everything by copy except for x that is captured by reference.
|\[&, this](){} |Captures everything by reference except for pointer this that is captured by copy (this is always captured by copy).
|\[x, x](){} |Error, x is captured twice.
|\[&, &x](){} |Error, everything is captured by reference, and we cannot specify again to capture x by reference.
|\[=, =x](){} |Error, everything is captured by copy, and we cannot specify again to capture x by copy.
|\[&this](){} |Error, the pointer this is always captured by copy.
|\[&, =](){} |Error, cannot capture everything both by copy and by reference.
|\[x=expr](){} |x is a data member of the lambda's closure initialized from the expression expr.
|\[&x=expr](){} |x is a reference data member of the lambda's closure initialized from the expression expr.
