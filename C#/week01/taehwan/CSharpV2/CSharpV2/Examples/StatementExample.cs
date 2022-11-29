namespace CSharpV2.StatementExample
{
    class TestStatement
    {
        public TestStatement()
        {
            Test();
        }

        private void Test()
        {
            int counter;

            counter = 1;

            int[] radii = { 15, 32, 108, 74, 9 };
            const double pi = 3.14159;

            foreach (int radius in radii)
            {
                double circumference = pi * (2 * radius);

                System.Console.WriteLine("Radius of circle #{0} is {1}. Circumference = {2:N2}",
                    counter, radius, circumference);

                counter++;
            }
        }
    }
}