using System;

namespace CSharpV7.OutVariables
{
    /*
    class CS0663_Example
    {
        // Compiler error CS0663: "Cannot define overloaded
        // methods that differ only on ref and out".
        public void SampleMethod(out int i) { }
        public void SampleMethod(ref int i) { }
    }
    */

    class OutOverloadExample
    {
        public void SampleMethod(int i) { }
        public void SampleMethod(out int i) => i = 5;
    }

    public class RunExample1
    {
        void Method(out int answer, out string message, out string stillNull)
        {
            answer = 44;
            message = "I've been returned";
            stillNull = null;
        }

        public RunExample1()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            /// 
            int initializeInMethod;
            OutArgExample(out initializeInMethod);
            Console.WriteLine(initializeInMethod);     // value is now 44

            void OutArgExample(out int number)
            {
                number = 44;
            }
            ///

            ///
            int argNumber;
            string argMessage, argDefault;
            Method(out argNumber, out argMessage, out argDefault);
            Console.WriteLine(argNumber);
            Console.WriteLine(argMessage);
            Console.WriteLine(argDefault == null);
            ///

            ///
            string numberAsString = "1640";

            int number1;
            if (Int32.TryParse(numberAsString, out number1))
                Console.WriteLine($"Converted '{numberAsString}' to {number1}");
            else
                Console.WriteLine($"Unable to convert '{numberAsString}'");

            if (Int32.TryParse(numberAsString, out int number2))
                Console.WriteLine($"Converted '{numberAsString}' to {number2}");
            else
                Console.WriteLine($"Unable to convert '{numberAsString}'");

            if (Int32.TryParse(numberAsString, out var number3))
                Console.WriteLine($"Converted '{numberAsString}' to {number3}");
            else
                Console.WriteLine($"Unable to convert '{numberAsString}'");
            ///

        }
    }
}