using System;
using System.Collections.Generic;

namespace CSharpV2.OperatorExample
{
    class OperatorExample
    {
        public OperatorExample()
        {
            Test();
        }

        private void assignment()
        {
            int a, b, c;
            a = 7;
            b = a;
            c = b++;
            b = a + b * c;
            c = a >= 100 ? b : c / 10;
            a = (int)Math.Sqrt(b * b + c * c);

            string s = "String literal";
            char l = s[s.Length - 1];

            var numbers = new List<int>(new[] { 1, 2, 3 });
            b = numbers.FindLast(n => n > 1);
        }

        private void Test()
        {
            assignment();
        }
    }
}