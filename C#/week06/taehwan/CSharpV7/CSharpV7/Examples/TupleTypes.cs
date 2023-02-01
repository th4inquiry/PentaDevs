using System;

namespace CSharpV7.TupleTypes
{
    public class RunExample2
    {
        public RunExample2()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            (double, int) t1 = (4.5, 3);
            Console.WriteLine($"Tuple with elements {t1.Item1} and {t1.Item2}.");
            // Output:
            // Tuple with elements 4.5 and 3.

            (double Sum, int Count) t2 = (4.5, 3);
            Console.WriteLine($"Sum of {t2.Count} elements is {t2.Sum}.");
            // Output:
            // Sum of 3 elements is 4.5.

            ///
            var t =
                (1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                11, 12, 13, 14, 15, 16, 17, 18,
                19, 20, 21, 22, 23, 24, 25, 26);
            Console.WriteLine(t.Item26);  // output: 26
            ///

            ///
            var xs = new[] { 4, 7, 9 };
            var limits = FindMinMax(xs);
            Console.WriteLine($"Limits of [{string.Join(" ", xs)}] are {limits.min} and {limits.max}");
            // Output:
            // Limits of [4 7 9] are 4 and 9

            var ys = new[] { -9, 0, 67, 100 };
            var (minimum, maximum) = FindMinMax(ys);
            Console.WriteLine($"Limits of [{string.Join(" ", ys)}] are {minimum} and {maximum}");
            // Output:
            // Limits of [-9 0 67 100] are -9 and 100

            (int min, int max) FindMinMax(int[] input)
            {
                if (input is null || input.Length == 0)
                {
                    throw new ArgumentException("Cannot find minimum and maximum of a null or empty array.");
                }

                var min = int.MaxValue;
                var max = int.MinValue;
                foreach (var i in input)
                {
                    if (i < min)
                    {
                        min = i;
                    }
                    if (i > max)
                    {
                        max = i;
                    }
                }
                return (min, max);
            }
            ///

            ///
            var x = (Sum: 4.5, Count: 3);
            Console.WriteLine($"Sum of {x.Count} elements is {x.Sum}.");

            (double Sum, int Count) d = (4.5, 3);
            Console.WriteLine($"Sum of {d.Count} elements is {d.Sum}.");
            ///
        }
    }
}