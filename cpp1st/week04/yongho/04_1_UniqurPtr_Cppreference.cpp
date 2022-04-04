#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
 
// helper class for runtime polymorphism demo below
struct BaseClass
{
    virtual ~BaseClass() = default; 
    virtual void bar() { std::cout << "BaseClass::bar()\n"; }
};
 
struct DerivedClass : BaseClass
{
    DerivedClass() { std::cout << "DerivedClass Ctor()\n"; }
    ~DerivedClass() { std::cout << "DerivedClass Dtor()\n"; }
 
    void bar() override { std::cout << "Derived::bar()\n"; }
};
 
// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<DerivedClass> pass_through(std::unique_ptr<DerivedClass> p)
{
    p->bar();
    return p;
}
 
// helper function for the custom deleter demo below
void close_file(std::FILE* fp)
{
    std::fclose(fp);
}
 
// unique_ptr-based linked list demo
struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };
 
    std::unique_ptr<Node> head;
 
    ~List()
    {
        // destroy list nodes sequentially in a loop, the default destructor
        // would have invoked its `next`'s destructor recursively, which would
        // cause stack overflow for sufficiently large lists.
        while (head)
            head = std::move(head->next);
    }
 
    void push(int data)
    {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};
 
int main()
{
    std::cout << "1) Unique ownership semantics demo\n";
    {
        std::unique_ptr<DerivedClass> p = std::make_unique<DerivedClass>();
        std::cout << "p.get()=" << p.get() << std::endl;

        // Transfer ownership to `pass_through`, which in turn transfers ownership back through the return value
        //std::unique_ptr<D> q = pass_through(p); //Compile error C2280 : Attepting to reference a deleted function
        std::unique_ptr<DerivedClass> q = pass_through(std::move(p));
        std::cout << "p.get()=" << p.get() << std::endl;
        std::cout << "q.get()=" << q.get() << std::endl;

        p.reset(new DerivedClass());
        std::cout << "After p.reset(new DerivedClass())" << std::endl;
        std::cout << "p.get()=" << p.get() << std::endl;
        std::cout << "q.get()=" << q.get() << std::endl;

        p.swap(q);
        std::cout << "After p.swap(q)" << std::endl;
        std::cout << "p.get()=" << p.get() << std::endl;
        std::cout << "q.get()=" << q.get() << std::endl;

        p.release();
        q.release();
        std::cout << "After p.release() q.release()" << std::endl;
        std::cout << "p.get()=" << p.get() << std::endl;
        std::cout << "q.get()=" << q.get() << std::endl;
    }
 
    std::cout << "\n" "2) Runtime polymorphism demo\n";
    {
        // Create a derived resource and point to it via base type
        std::unique_ptr<BaseClass> p = std::make_unique<DerivedClass>();
 
        // Dynamic dispatch works as expected : method() in derived class is called
        p->bar();
    }
 
    std::cout << "\n" "3) Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("demo.txt", "r"), &close_file);
        
        std::cout << "&close_file=" << &close_file << std::endl;
        std::cout << "fp.get_deleter()=" << fp.get_deleter() << std::endl;

        if (fp)
            std::cout << char(std::fgetc(fp.get())) << '\n';
    } // `close_file()` called here (if `fp` is not null)
 
    std::cout << "\n" "4) Custom lambda-expression deleter and exception safety demo\n";
    try
    {
        std::unique_ptr<DerivedClass, void(*)(DerivedClass*)> p(new DerivedClass, [](DerivedClass* ptr)
        {
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });

        std::cout << "p.get()=" << p.get() << std::endl;
        throw std::runtime_error(""); // `p` would leak here if it were instead a plain pointer
    }
    catch (const std::exception&) { std::cout << "Caught exception\n"; }
 
    std::cout << "\n" "5) Array form of unique_ptr demo\n";
    {
        std::unique_ptr<DerivedClass[]> p(new DerivedClass[3]);
    } // Constructor() and Destructor() are called 3 times
 
    std::cout << "\n" "6) Linked list demo\n";
    {
        List wall;
        for (int beer = 0; beer != 1'000'000; ++beer)
            wall.push(beer);

        std::cout << "1'000'000 bottles of beer on the wall...\n";
    } // destroys all the beers
}