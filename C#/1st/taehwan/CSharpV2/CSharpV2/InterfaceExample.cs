using System;

namespace CSharpV2.InterfaceExample
{
    interface IEqautable<T>
    {
        bool Equals(T obj);
    }

    public class Car : IEqautable<Car>
    {
        public string? Make { get; set; }
        public string? Model { get; set; }
        public string? Year { get; set; }

        public bool Equals(Car? car)
        {
            return (this.Make, this.Model, this.Year) == (car?.Make, car?.Model, car?.Year);
        }
    }

    class TestInterface
    {
        public TestInterface()
        {
            Test();
        }

        private void Test()
        {
            var car1 = new Car();
            car1.Make = "SUSKO";
            car1.Model = "OAK";
            car1.Year = "2023";

            var car2 = new Car();
            car1.Make = "SUSKO";
            car1.Model = "MAPLE";
            car1.Year = "2024";

            if (car2.Equals(car1))
            {
                Console.WriteLine("The car2 is same as car1.");
            }
            else
            {
                Console.WriteLine("The car2 is not same as car1.");
            }
        }
    }
}