using System;
using System.Collections.Generic;

namespace CSharpV2.GenericsExample
{
    public class GenericList<T>
    {
        private class Node
        {
            public Node(T t)
            {
                next = null;
                data = t;
            }

            private Node? next;
            public Node? Next
            {
                get { return next; }
                set { next = value; }
            }

            private T data;

            public T Data
            {
                get { return data; }
                set { data = value; }
            }
        }

        private Node? head;

        public GenericList()
        {
            head = null;
        }

        public void AddHead(T t)
        {
            Node n = new Node(t);
            n.Next = head;
            head = n;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node? current = head;

            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }
    }

    class TestGenerics
    {
        public TestGenerics()
        {
            Test();
        }

        private void Test()
        {
            GenericList<int> list = new GenericList<int>();

            for (int x = 0; x < 10; x++)
            {
                list.AddHead(x);
            }

            foreach (int i in list)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine("\nDone");
        }
    }
}