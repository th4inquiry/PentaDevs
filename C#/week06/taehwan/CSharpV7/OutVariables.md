# out parameter modifier (C# Reference)

The ```out``` keyword causes arguments to be passed by reference. It makes the formal parameter an alias for the argument, which must be a variable. In other words, any operation on the parameter is made on the argument. It is like the ```ref``` keyword, except that ```ref``` requires that the variable be initialized before it is passed. It is also like the in keyword, except that in does not allow the called method to modify the argument value. To use an ```out``` parameter, both the method definition and the calling method must explicitly use the ```out``` keyword. For example:

```c#
int initializeInMethod;
OutArgExample(out initializeInMethod);
Console.WriteLine(initializeInMethod);     // value is now 44

void OutArgExample(out int number)
{
    number = 44;
}
```

> ¨Õ Note <br>
> The ```out``` keyword can also be used with a generic type parameter to specify that the type parameter is covariant. For more information on the use of the ```out``` keyword in this context, see **out (Generic Modifier)**.

Variables passed as ```out``` arguments do not have to be initialized before being passed in a method call. However, the called method is required to assign a value before the method returns.

The ```in```, ```ref```, and ```out``` keywords are not considered part of the method signature for the purpose of overload resolution. Therefore, methods cannot be overloaded if the only difference is that one method takes a ```ref``` or ```in``` argument and the other takes an ```out``` argument. The following code, for example, will not compile:

```c#
class CS0663_Example
{
    // Compiler error CS0663: "Cannot define overloaded
    // methods that differ only on ref and out".
    public void SampleMethod(out int i) { }
    public void SampleMethod(ref int i) { }
}
```

Overloading is legal, however, if one method takes a ref, in, or out argument and the other has none of those modifiers, like this:

```c#
class OutOverloadExample
{
    public void SampleMethod(int i) { }
    public void SampleMethod(out int i) => i = 5;
}
```

The compiler chooses the best overload by matching the parameter modifiers at the call site to the parameter modifiers used in the method call.

Properties are not variables and therefore cannot be passed as ```out``` parameters.

You can't use the ```in```, ```ref```, and ```out``` keywords for the following kinds of methods:

* Async methods, which you define by using the async modifier.

* Iterator methods, which include a yield return or yield break statement.

In addition, extension methods have the following restrictions:

* The ```out``` keyword cannot be used on the first argument of an extension method.
* The ```ref``` keyword cannot be used on the first argument of an extension method when the argument is not a struct, or a generic type not constrained to be a struct.
* The ```in``` keyword cannot be used unless the first argument is a struct. The ```in``` keyword cannot be used on any generic type, even when constrained to be a struct.

# Declaring ```out``` parameters

Declaring a method with ```out``` arguments is a classic workaround to return multiple values. Consider value tuples for similar scenarios. The following example uses ```out``` to return three variables with a single method call. The third argument is assigned to null. This enables methods to return values optionally.

```c#
void Method(out int answer, out string message, out string stillNull)
{
    answer = 44;
    message = "I've been returned";
    stillNull = null;
}

int argNumber;
string argMessage, argDefault;
Method(out argNumber, out argMessage, out argDefault);
Console.WriteLine(argNumber);
Console.WriteLine(argMessage);
Console.WriteLine(argDefault == null);

// The example displays the following output:
//      44
//      I've been returned
//      True
```

# Calling a method with an ```out``` argument

You can declare a variable in a separate statement before you pass it as an ```out``` argument. The following example declares a variable named ```number``` before it is passed to the Int32.TryParse method, which attempts to convert a string to a number.

```c#
string numberAsString = "1640";

int number;
if (Int32.TryParse(numberAsString, out number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```

You can also declare the ```out``` variable in the argument list of the method call, rather than in a separate variable declaration. This produces more compact, readable code, and also prevents you from inadvertently assigning a value to the variable before the method call. The following example is like the previous example, except that it defines the ```number``` variable in the call to the Int32.TryParse method.

```c#
string numberAsString = "1640";

if (Int32.TryParse(numberAsString, out int number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```

In the previous example, the ```number``` variable is strongly typed as an ```int```. You can also declare an implicitly typed local variable, as the following example does.

```c#
string numberAsString = "1640";

if (Int32.TryParse(numberAsString, out var number))
    Console.WriteLine($"Converted '{numberAsString}' to {number}");
else
    Console.WriteLine($"Unable to convert '{numberAsString}'");
// The example displays the following output:
//       Converted '1640' to 1640
```

