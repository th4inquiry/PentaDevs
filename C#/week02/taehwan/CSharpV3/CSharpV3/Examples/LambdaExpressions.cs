using System;

namespace CSharpV3.AnonymousTypes
{
    public class RunExample4
    {
        public RunExample4()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            Func<int, int> square = x => x * x;
            Console.WriteLine(square(5));

            System.Linq.Expressions.Expression<Func<int, int>> e = x => x * x;
            Console.WriteLine(e);

            Action<string> greet = name =>
            {
                string greeting = $"Hello {name}!";
                Console.WriteLine(greeting);
            };
            greet("World");

            Func<int, int, bool> testForEquality = (x, y) => x == y;
            Console.WriteLine(testForEquality(2, 3));
        }
    }
}