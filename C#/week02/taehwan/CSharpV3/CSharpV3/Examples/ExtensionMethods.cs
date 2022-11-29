using System;
using System.Linq;

namespace CSharpV3.ExtensionMethods
{
    public static class RunExample5
    {
        public static int WordCount(this string str)
        {
            return str.Split(new char[] { ' ', '.', '?' },
                StringSplitOptions.RemoveEmptyEntries).Length;
        }

        public static void TestExecute()
        {
            int[] ints = { 10, 45, 15, 39, 21, 26 };
            var result = ints.OrderBy(g => g);
            foreach (var i in result)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();

            string s = "Hello Extension Methods";
            Console.WriteLine(s.WordCount());
        }
    }
}