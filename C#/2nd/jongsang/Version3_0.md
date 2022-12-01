# C# Version 3.0
- [Auto-implemented properties](../programming-guide/classes-and-structs/auto-implemented-properties.md)
- [Anonymous types](../fundamentals/types/anonymous-types.md)
- [Query expressions](../linq/query-expression-basics.md)
- [Lambda expressions](../language-reference/operators/lambda-expressions.md)
- [Expression trees](../expression-trees.md)
- [Extension methods](../programming-guide/classes-and-structs/extension-methods.md)
- [Implicitly typed local variables](../language-reference/statements/declarations.md#implicitly-typed-local-variables)
- [Partial methods](../language-reference/keywords/partial-method.md)
- [Object and collection initializers](../programming-guide/classes-and-structs/object-and-collection-initializers.md)
<br>

References
- [The history of C#, Microsoft](https://learn.microsoft.com/en-us/dotnet/csharp/whats-new/csharp-version-history)
- 시작하세요! C# 9.0, 정성태
<br>
<br>
<br>



# Auto-Implemented Properties
When you declare a property as shown in the following example, the compiler creates a private, anonymous `private instance` backing field that can only be accessed through the property's `get` and `set` accessors.
- It is useful to design the simple class
- If you need to add some logic to property, you just add the private instance and the loginc inside the property easily.

```c#
// This class is mutable. Its data can be modified from
// outside the class.
public class Customer
{
    // Auto-implemented properties for trivial get and set
    public double TotalPurchases { get; set; }
    public string Name { get; set; }
    public int CustomerId { get; set; }

    // Constructor
    public Customer(double purchases, string name, int id)
    {
        TotalPurchases = purchases;
        Name = name;
        CustomerId = id;
    }

    // Methods
    public string GetContactInfo() { return "ContactInfo"; }
    public string GetTransactionHistory() { return "History"; }

    // .. Additional methods, events, etc.
}

class Program
{
    static void Main()
    {
        // Initialize a new object.
        Customer cust1 = new Customer(4987.63, "Northwind", 90108);

        // Modify a property.
        cust1.TotalPurchases += 499.99;
    }
}
```
<br>

You can initialize auto-implemented properties similarly to fields:
```c#
public string FirstName { get; set; } = "Jane";
``` 
<br>

## By compiler
Auto-implemented properties code is converted by the compiler as the below.
```c#
// Before
class Person
{
    public string Name { get; set; }
}

// After
class Person
{
    private string NameByCompiler; // Auto generated name by compiler
    public string Name
    {
        get { return NameByCompiler; }
        set { NameByComiler = value; }
    }
}
```

References
- [Auto-Implemented Properties (C# Programming Guide)](https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties)
- 시작하세요! C# 9.0, 정성태
<br>
<br>

## How to implement a lightweight class with auto-implemented properties
Refer to [How to implement a lightweight class with auto-implemented properties (C# Programming Guide)](https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/how-to-implement-a-lightweight-class-with-auto-implemented-properties)

<br>
<br>
<br>

# Object Initializer
Object initializers let you assign values to any `accessible fields or properties` of an object at creation time `without having to invoke a constructor followed by lines of assignment statements`.

### Example code 1

```c#
// Without object initialization
using System;
class Person
{
    string _name;
    int _age;

    public Person()
        : this(string.Empty, 0)
    {

    }
    public Person(string name)
        : this(name, 0)
    {

    }
    public Person(string name, int age)
    {
        _age = age;
        _name = name;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Person p = new Person("Anders", 10);
    }
}

// With object initialization
using System;

class Person
{
    string _name;
    int _age;

    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }
    public int Age
    {
        get { return _age; }
        set { _age = value; }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Person p1 = new Person();
        Person p2 = new Person { Name = "Anders" };
        Person p3 = new Person { Age = 10 };
        Person p4 = new Person { Name = "Anders", Age = 10 };
    }
}
```
<br>

### Example code 2
```c#
public class Cat
{
    // Auto-implemented properties.
    public int Age { get; set; }
    public string Name { get; set; }

    public Cat()
    {
    }

    public Cat(string name)
    {
        this.Name = name;
    }
}
...

Cat cat = new Cat { Age = 10, Name = "Fluffy" };
Cat sameCat = new Cat("Fluffy"){ Age = 10 };
```
<br>

### Example code 3
```c#
public class Matrix
{
    private double[,] storage = new double[3, 3];

    public double this[int row, int column]
    {
        // The embedded array will throw out of range exceptions as appropriate.
        get { return storage[row, column]; }
        set { storage[row, column] = value; }
    }
}
...

var identity = new Matrix
{
    [0, 0] = 1.0,
    [0, 1] = 0.0,
    [0, 2] = 0.0,

    [1, 0] = 0.0,
    [1, 1] = 1.0,
    [1, 2] = 0.0,

    [2, 0] = 0.0,
    [2, 1] = 0.0,
    [2, 2] = 1.0,
};
```