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


Refer to [Interfaces](https://learn.microsoft.com/en-us/dotnet/csharp/fundamentals/types/interfaces)

## Interface Access Modifiers
Refer to [Interface Access Modifiers](https://www.techpointfunda.com/2020/08/interface-access-modifiers-csharp.html)
<br>


























