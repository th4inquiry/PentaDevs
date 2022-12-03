using System.Linq;

namespace CSharpV3.AnonymousTypes
{
    public class RunExample2
    {
        public RunExample2()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            var v = new { Amount = 108, Message = "Hello" };

            var products = new[] { new { Color = "red", Price = 99.9 }, new { Color = "blue", Price = 9.9 } };

            var productQuery =
                from prod in products
                select new { prod.Color, prod.Price };

            foreach (var t in productQuery)
            {
                System.Console.WriteLine("Color={0}, Price={1}", t.Color, t.Price);
            }

            var apple = new { Item = "apples", Price = 1.35 };
            /// var onSale = apple with { Price = 0.79 };       // example of 'with' expression supporting in C# 9.0
            System.Console.WriteLine(apple.ToString());
        }
    }
}