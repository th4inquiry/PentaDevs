﻿namespace CSharpV2
{
    using ClassExample;
    using StructExample;
    using InterfaceExample;
    using StatementExample;
    using GenericsExample;

    class ProgramExecutable
    {
        static void Main(string[] args)
        {
            var example1 = new TestClass();
            var example2 = new TestStruct();
            var example3 = new TestInterface();
            var example4 = new TestStatement();
            var example5 = new TestGenerics();
        }
    }
}
