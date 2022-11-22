using System;

namespace CSharpV2.StructExample
{
    public readonly struct Coords
    {
        public Coords(double x, double y)
        {
            X = x;
            Y = y;
        }

        public double X { get; }
        public double Y { get; }

        public override string ToString() => $"({X}, {Y})";
    }

    class TestStruct
    {
        public TestStruct()
        {
            Test();
        }

        private void Test()
        {
            var p1 = new Coords(0, 0);
            Console.WriteLine(p1);
        }
    }
}