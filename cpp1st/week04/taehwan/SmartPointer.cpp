///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Examples of smart pointers

#include <memory>
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>

#pragma region EXAMPLE_CODE

using namespace std;

struct Foo {
public:
    virtual ~Foo() = default;
    virtual void show() { cout << "Foo::show()" << endl; }
};

struct Bar : Foo {
public:
    Bar() { cout << "Bar::Bar()" << endl; }
    ~Bar() { cout << "Bar::~Bar()" << endl; }

    void show() override { cout << "Bar::show()" << endl; }
};

unique_ptr<Bar> pass_through(unique_ptr<Bar> ptr) {
    ptr->show();
    return ptr;
}

struct Base {
    Base() { cout << "\tBase::Base()" << endl; }
    ~Base() { cout << "\tBase::~Base()" << endl; }
};

struct Derived : public Base {
    Derived() { cout << "\tDerived::Derived()" << endl; }
    ~Derived() { cout << "\tDerived::~Derived()" << endl; }
};

void initThread(shared_ptr<Base> ptr) {
    this_thread::sleep_for(chrono::seconds(1));
    shared_ptr<Base> local_ptr = ptr;

    {
        static mutex io_mutex;
        lock_guard<mutex> lk(io_mutex);
        cout << "local pointer in a thread: " << endl
             << "\tlocal_ptr.get() = " << local_ptr.get()
             << ", local_ptr.use_count() = " << local_ptr.use_count() << endl;
    }
}

weak_ptr<int> globalWeakPtr;

void observe() {
    cout << "globalWeakPtr.use_count() == " << globalWeakPtr.use_count() << "; ";
    if (shared_ptr<int> sharedPtr = globalWeakPtr.lock()) {
        cout << "*sharedPtr == " << *sharedPtr << endl;
    }
    else {
        cout << "globalWeakPtr is expired..." << endl;
    }
}

#pragma endregion EXAMPLE_CODE

class SmartPointers {
public:
    SmartPointers() {}

    void selectSmartPointer();
private:
    void runExampleUniquePtr();
    void runExampleSharedPtr();
    void runExampleWeakPtr();
    void runExampleAutoPtr();

    bool isTestEnd;
    int select;
};

void SmartPointers::selectSmartPointer() {
    isTestEnd = false;

    while (isTestEnd != true) {
        cout.setf(ios::left);
        cout << setw(20) << "1. unique_ptr";
        cout << setw(20) << "2. shared_ptr";
        cout << setw(20) << "3. weak_ptr";
        cout << setw(20) << "4. auto_ptr";
        cout << endl << "0. Back to list" << endl;
        cout << "Select number: ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 1:
                runExampleUniquePtr();
                break;
            case 2:
                runExampleSharedPtr();
                break;
            case 3:
                runExampleWeakPtr();
                break;
            case 4:
                runExampleAutoPtr();
                break;
            case 0:
                isTestEnd = true;
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
        cout << endl << endl;
    }
}

void SmartPointers::runExampleUniquePtr() {
    {
        unique_ptr<Bar> ptr1(new Bar);
        ptr1->show();

        cout << ptr1.get() << endl;     /// returns the memory address of ptr1

        unique_ptr<Bar> ptr2 = move(ptr1);  /// transfers ownership to ptr2
        ptr2->show();
        cout << ptr1.get() << endl;     /// shows NULL
        cout << ptr2.get() << endl;

        unique_ptr<Bar> ptr3 = move(ptr2);  /// transfers ownership to ptr3
        ptr3->show();
        cout << ptr1.get() << endl;     /// shows NULL
        cout << ptr2.get() << endl;     /// shows NULL
        cout << ptr3.get() << endl;
    }

    cout << endl;

    {
        unique_ptr<Bar> ptr1 = make_unique<Bar>();
        unique_ptr<Bar> ptr2 = pass_through(move(ptr1));
        assert(!ptr1);
    }

    cout << endl;

    {
        unique_ptr<Foo> ptr1 = make_unique<Bar>();      /// it can be allowed from the case of 'struct', but not allowed from 'class'
        ptr1->show();
    }

    cout << endl;

    try {
        unique_ptr<Bar, void(*)(Bar *)> ptr(new Bar, [](Bar * temp_ptr) {
            cout << "destroying from a custom deleter..." << endl;
            delete temp_ptr;
        });

        throw runtime_error("");
    }
    catch (const exception &) { cout << "Caught exception" << endl; }
}

void SmartPointers::runExampleSharedPtr() {
    shared_ptr<Base> ptr = make_shared<Derived>();

    cout << "Created a shared Derived (as a pointer to Base)" << endl
         << "\tptr.get() = " << ptr.get()
         << ", ptr.use_count() = " << ptr.use_count() << endl;

    thread t1(initThread, ptr), t2(initThread, ptr), t3(initThread, ptr);

    ptr.reset();

    cout << "Shared ownership between 3 threads and released" << endl
         << "ownership from main:" << endl
         << "\tptr.get() = " << ptr.get()
         << ", ptr.use_count() = " << ptr.use_count() << endl;

    t1.join();
    t2.join();
    t3.join();

    cout << "All threads completed, the last one deleted Derived" << endl;
}

void SmartPointers::runExampleWeakPtr() {
    {
        auto sharedPtr = make_shared<int>(42);
        globalWeakPtr = sharedPtr;

        observe();
    }
    observe();
}

void SmartPointers::runExampleAutoPtr() {
    auto_ptr<Bar> ptr1(new Bar);
    ptr1->show();

    cout << ptr1.get() << endl;

    auto_ptr<Bar> ptr2(ptr1);
    ptr2->show();

    cout << ptr1.get() << endl;
    cout << ptr2.get() << endl;
}