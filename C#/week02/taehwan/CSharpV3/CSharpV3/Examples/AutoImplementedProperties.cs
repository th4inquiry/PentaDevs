namespace CSharpV3.AutoImplementedProperties
{
    public class Customer
    {
        public double TotalPurchases { get; set; }
        public string Name { get; set; }
        public int CustomerId { get; set; }

        public Customer(double purchases, string name, int id)
        {
            TotalPurchases = purchases;
            Name = name;
            CustomerId = id;
        }

        public string GetContactInfo() { return "ContactInfo"; }
        public string GetTransactionHistory() { return "History"; }
    }

    public class RunExample1
    {
        public RunExample1()
        {
            TestExecute();
        }

        private void TestExecute()
        {
            Customer cust1 = new Customer(4987.63, "Northwind", 90108);
            cust1.TotalPurchases += 499.99;

            System.Console.WriteLine("{0}, {1}, {2}", cust1.TotalPurchases, cust1.Name, cust1.CustomerId);
            System.Console.WriteLine(cust1.GetContactInfo());
            System.Console.WriteLine(cust1.GetTransactionHistory());
        }
    }
}