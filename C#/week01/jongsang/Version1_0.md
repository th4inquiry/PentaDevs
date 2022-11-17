# C# version 1.0
Classes  
Structs  
Interfaces  
Events  
Properties  
Delegates  
Operators and expressions  
Statements  
Attributes  
<br>

# Classes
Refer to [Classes](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/types/classes)
<br>

# Structs
- Inherites ```System.Object```
- value type
- Can be instantiated with ```new``` or without it
- Can not declare the ```default constructor``` explicitly
- Compiler generates the default constructor even there the constructor with parameters exists (vice versa ```class```)
- In constructor with parameters, all fields must be assigned

```c#
   struct Vector
    {
        public int X;
        public int Y;

        public Vector(int x, int y)
        {
            this.X = x;
            this.Y = y;
        }

        public override string ToString()
        {
            return "X: " + this.X + ", Y = " + this.Y;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Vector v1 = new Vector();       // OK
            Vector v2;                      // OK
            Vector v3 = new Vector(5, 10);  // OK

            Console.WriteLine(v1);
            //Console.WriteLine(v2);          // Error, v2 is unassigned

            // The below all is the same
            Vector v4 = new Vector();       // Initialize all member to 0
            Vector v5;
            v5.X = 0;
            v5.Y = 0;
            Vector v6 = new Vector(0, 0);

            // copy value
            Vector v10 = new Vector(20, 30);
            Vector v11 = v10;
            v11.X = -20;
            v11.Y = -30;
            Console.WriteLine("v10 => {0}", v10);
            Console.WriteLine("v11 => {0}", v11);

        }
    }
```
<br>

# Interfaces
Interface is defined as ```Contract```.  

interface can be defined as the below.
```c#
access_modifier interface interface_name  
{  
    // method declarations  
}  
// access modifier => public or internal(default)
```


Refer to [Interfaces, Microsoft](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/types/interfaces)

## Interface Access Modifiers
Refer to [Interface Access Modifiers](https://www.techpointfunda.com/2020/08/interface-access-modifiers-csharp.html) (including C# 8.0)
<br>

## Example source code
```c#
public interface IInterfaceTest
{
    // Default access modifier is public
    void DefaultMethod();
    public void PublicMethod();

    // Provide the default implementation
    public void PublicMethod1()
    {
        PrivateMethod();
    }

    // protected member can be accessed by only derived class
    protected void ProtectedMethod();

    // private member must provide default implementation
    private void PrivateMethod()
    {
        Console.WriteLine("PrivateMethod is called");
    }
}

public class InterfaceTest : IInterfaceTest
{
    public void DefaultMethod()
    {
        Console.WriteLine("DefaultInterface is called");
    }
    public void PublicMethod()
    {
        Console.WriteLine("PublicMethod is called");
    }

    // If this method is commented out, the default method of IInterfaceTest would be called
    void IInterfaceTest.PublicMethod1()
    {
        Console.WriteLine("PublicMethod1 is called");
    }

    void IInterfaceTest.ProtectedMethod()
    {
        Console.WriteLine("ProtectedMethod is called");
    }
}

...
static void TestInterface()
{
    IInterfaceTest iInterfaceTest = new InterfaceTest();
    iInterfaceTest.DefaultMethod();
    iInterfaceTest.PublicMethod();
    iInterfaceTest.PublicMethod1();
    //iInterfaceTest.ProtectedMethod();       // Error

    InterfaceTest interfaceTest = new InterfaceTest();
    interfaceTest.DefaultMethod();
    interfaceTest.PublicMethod();
    //interfaceTest.PublicMethod1();            // Error, can be accessed by only IInterfaceTest type
    //interfaceTest.ProtectedMethod();          // Error
}

// Output
// DefaultInterface is called
// PublicMethod is called
// PublicMethod1 is called
// DefaultInterface is called
// PublicMethod is called
```

# Delegate
A ```delegate``` is a type that represents references to methods with a particular parameter list and return type.
<br>
<br>
```delegate``` can be declared as the below.

```c#
access-modifier delegate return-type (parameter-list);

// Example
public class Disk
{
    public delegate int FuncDelegate(object arg);
    public int Clean(object arg)
    {
        Console.WriteLine("Working");
        return 0;
    }
}
...

Disk disk = new Disk();
Disk.FuncDelegate cleanFunc = new Disk.FuncDelegate(disk.Clean);
Disk.FuncDelegate cleanFunc2 = disk.Clean; // since C# 2.0

```
<br>

## Multicasting
A ```delegate``` can call more than one method when invoked. This is referred to as ```multicasting```.  

```c#
public class Disk
{
    // Multicasting
    public delegate void CalcDelegate(int x, int y);

    public static void Add(int x, int y) { Console.WriteLine(x + y); }
    public static void Subtract(int x, int y) { Console.WriteLine(x - y); }
    public static void Multiply(int x, int y) { Console.WriteLine(x * y); }
    public static void Divide(int x, int y) { Console.WriteLine(x / y); }
}

static void TestDelegate()
{
    // Multicasting
    Disk.CalcDelegate calc = Disk.Add;
    calc += Disk.Subtract;
    calc += Disk.Multiply;
    calc += Disk.Divide;

    calc(10, 5);
}

// output
// 15
// 5
// 50
// 2
```

Acutually, the preceding "```+```" expression regarding ```delegate``` is converted into the below by the compiler.
<br>

```c#
 // Multicasting
var calc = new Disk.CalcDelegate(Disk.Add);
var calcSub= new Disk.CalcDelegate(Disk.Subtract);
var calcMul = new Disk.CalcDelegate(Disk.Multiply);
var calcDiv = new Disk.CalcDelegate(Disk.Divide);

calc = Disk.CalcDelegate.Combine(calc, calcSub) as Disk.CalcDelegate;
calc = Disk.CalcDelegate.Combine(calc, calcMul) as Disk.CalcDelegate;
calc = Disk.CalcDelegate.Combine(calc, calcDiv) as Disk.CalcDelegate;

calc(10, 5);
```

























