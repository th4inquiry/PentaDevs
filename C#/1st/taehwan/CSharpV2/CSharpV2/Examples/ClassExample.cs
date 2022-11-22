using System;

namespace CSharpV2.ClassExample
{
    public class Person
    {
        public Person()
        {
            Name = "unknown";
        }

        public Person(string name)
        {
            Name = name;
        }

        public string Name { get; }

        public override string ToString()
        {
            return Name;
        }
    }


    class TestClass
    {
        public TestClass()
        {
            Test();
        }

        private void Test()
        {
            var person1 = new Person();
            Console.WriteLine(person1.Name);

            var person2 = new Person("TaeHwan Kim");
            Console.WriteLine(person2.Name);
            Console.WriteLine(person2);
        }
    }
}