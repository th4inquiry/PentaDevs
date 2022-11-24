using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using MyCSharpLib;

namespace Version1_0.Struct
{
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
}

namespace Version1_0.Interface
{
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

    public class Person : IPerson
    {
        private string name;

        public string GetName()
        {
            return name;
        }
    }
}

namespace Version1_0.Delegate
{
    public class Disk : EventArgs
    {
        public delegate int FuncDelegate(object arg);
        public int Clean(object arg)
        {
            Console.WriteLine("Working");
            return 0;
        }

        // Multicasting
        public delegate void CalcDelegate(int x, int y);

        public static void Add(int x, int y) { Console.WriteLine(x + y); }
        public static void Subtract(int x, int y) { Console.WriteLine(x - y); }
        public static void Multiply(int x, int y) { Console.WriteLine(x * y); }
        public static void Divide(int x, int y) { Console.WriteLine(x / y); }
    }
}

namespace Version1_0.Events
{
    class EventTest
    {
        public event EventHandler myTestEventHandler;
    }
}

namespace Version1_0.Iterator
{
    public class NaturalNumber : IEnumerable<int>
    {
        public IEnumerator<int> GetEnumerator()
        {
            return new NaturalNumberEnumerator();
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return new NaturalNumberEnumerator();
        }
    }
    public class NaturalNumberEnumerator : IEnumerator<int>
    {
        int _current;

        public int Current { get { return _current; } }
        object IEnumerator.Current { get { return _current; } }
        public void Dispose() { }
        public bool MoveNext()
        {
            _current++;
            return true;
        }
        public void Reset()
        {
            _current = 0;
        }
    }

    public class YieldNaturalNumber
    {
        public static IEnumerable<int> Next()
        {
            int _start = 0;
            while(true)
            {
                _start++;
                yield return _start;
            }
        }

        public static IEnumerable SomeNumbers()
        {
            yield return 3;
            yield return 5;
            yield return 8;
        }
    }

}

namespace Version1_0.Attributes
{
    public class AuthorAttribute : System.Attribute
    {
        string name;
        int version;

        public int Version
        {
            get { return version; }
            set { version = value; }
        }

        public AuthorAttribute(string name)
        {
            this.name = name;
        }
    }

    [Author("JongSang", Version = 1)]
    public class MyAttrTest
    {
        string testString;
        public MyAttrTest(string str)
        {
            testString = str;
        }

        public void Print()
        {
            Console.WriteLine(testString);
        }
    }

    [Obsolete("ThisClass is obsolete. Use ThisClass2 instead.")]
    public class ThisClass
    {
    }

    [System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]
    struct TestUnion
    {
        [System.Runtime.InteropServices.FieldOffset(0)]
        public int i;

        [System.Runtime.InteropServices.FieldOffset(0)]
        public double d;

        [System.Runtime.InteropServices.FieldOffset(0)]
        public char c;

        [System.Runtime.InteropServices.FieldOffset(0)]
        public byte b;
    }
}
namespace Version1_0
{
    using Struct;
    using Interface;
    using Delegate;
    using Iterator;
    using Attributes;
    class Program
    {
        static void TestStruct()
        {
            Console.WriteLine("\n==== Test Struct ====");

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
        static void TestInterface()
        {
            Console.WriteLine("\n==== Test Interface ====");

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
        static void TestDelegate()
        {
            Console.WriteLine("\n==== Test Delegate ====");

            var disk = new Disk();
            Disk.FuncDelegate clean = new Disk.FuncDelegate(disk.Clean);
            Disk.FuncDelegate clean2 = disk.Clean;       // since C# 2.0

            clean(null);
            clean2(null);

            // Multicasting
            Disk.CalcDelegate calc = Disk.Add;
            calc += Disk.Subtract;
            calc += Disk.Multiply;
            calc += Disk.Divide;

            calc(10, 5);
        }
        static void EqualTestDelegate()
        {
            Console.WriteLine("\n==== Equal Test Delegate ====");

            // Multicasting
            var calc = new Disk.CalcDelegate(Disk.Add);
            var calcSub= new Disk.CalcDelegate(Disk.Subtract);
            var calcMul = new Disk.CalcDelegate(Disk.Multiply);
            var calcDiv = new Disk.CalcDelegate(Disk.Divide);

            calc = Disk.CalcDelegate.Combine(calc, calcSub) as Disk.CalcDelegate;
            calc = Disk.CalcDelegate.Combine(calc, calcMul) as Disk.CalcDelegate;
            calc = Disk.CalcDelegate.Combine(calc, calcDiv) as Disk.CalcDelegate;
            
            calc(10, 5);
        }

        static void TestIterator()
        {
            Console.WriteLine("\n==== Test Iterator ====");

            NaturalNumber number = new NaturalNumber();
            foreach (var n in number)
            {
                Console.WriteLine(n);
            }

            foreach(var nn in YieldNaturalNumber.Next())
            {
                Console.WriteLine(nn);
            }

            foreach(var p in YieldNaturalNumber.SomeNumbers())
            {
                Console.WriteLine(p);
            }
        }

        static void TestAttribute()
        {
            Console.WriteLine("\n==== Test Attributes ====");
            var myAttrTest = new MyAttrTest("Test");
            var thisClass = new ThisClass();

            TestUnion testUnion;
            testUnion.d = 100;
        }

        // Import user32.dll (containing the function we need) and define
        // the method corresponding to the native function.
        [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        private static extern int MessageBox(IntPtr hWnd, string lpText, string lpCaption, uint uType);


        static void Main(string[] args)
        {
            TestStruct();
            TestInterface();
            TestDelegate();
            EqualTestDelegate();
            TestIterator();
            TestAttribute();

            // Invoke the function as a regular managed method.
            MessageBox(IntPtr.Zero, "Command-line message box", "Attention!", 0);

        }
    }
}
