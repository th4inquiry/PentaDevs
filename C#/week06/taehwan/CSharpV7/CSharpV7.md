# C# version 7.0

*Released March, 2017*

C# version 7.0 was released with Visual Studio 2017. This version has some evolutionary and cool stuff in the vein of C# 6.0. Here are some of the new features:

* [Out variables](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/out-parameter-modifier)
* [Tuples and deconstruction](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/value-tuples)
* [Pattern matching](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/functional/pattern-matching)
* [Local functions](https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/local-functions)
* [Expanded expression bodied members](https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/statements-expressions-operators/expression-bodied-members)
* [Ref locals](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/statements/declarations#ref-locals)
* [Ref returns](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/statements/jump-statements#ref-returns)

Other features included:
* [Discards](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/functional/discards)
* [Binary Literals and Digit Separators](https://www.tutorialspoint.com/what-are-binary-literals-and-digit-separators-in-chash-7-0)
* [Throw expressions](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/throw#the-throw-expression)

All of these features offer new capabilities for developers and the opportunity to write cleaner code than ever. A highlight is condensing the declaration of variables to use with the ```out``` keyword and by allowing multiple return values via tuple. .NET Core now targets any operating system and has its eyes firmly on the cloud and on portability. These new capabilities certainly occupy the language designers' thoughts and time, in addition to coming up with new features.

# C# version 7.1

*Released August, 2017*

C# started releasing point releases with C# 7.1. This version added the language version selection configuration element, three new language features, and new compiler behavior.

The new language features in this release are:

* [async Main method](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/program-structure/main-command-line)
  * The entry point for an application can have the async modifier.
* [default literal expressions](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/operators/default#default-literal)
  * You can use default literal expressions in default value expressions when the target type can be inferred.
* [Inferred tuple element names](https://gunnarpeipman.com/csharp-inferred-tuple-names)
  * The names of tuple elements can be inferred from tuple initialization in many cases.
* [Pattern matching on generic type parameters](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/proposals/csharp-7.1/generics-pattern-match)
  * You can use pattern match expressions on variables whose type is a generic type parameter.

Finally, the compiler has two options -refout and -refonly that control reference assembly generation
