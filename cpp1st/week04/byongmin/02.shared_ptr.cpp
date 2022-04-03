#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Cat
{
public:
    explicit Cat() { cout << "Cat ctor() ++" << endl; }
    ~Cat() { cout << "Cat dtor() --" << endl; }
    
    void print()
    {
        cout << "called print()" << endl;
    }
};


void compare_Unique_Shared()
{
    // unique ptr
    vector<unique_ptr<Cat>> vecUnique;
    auto uniqueCat = make_unique<Cat>();

    vecUnique.emplace_back(move(uniqueCat));
    vecUnique.erase(vecUnique.begin());

    cout << ">>> unique end!" << endl;

    // shared ptr
    vector<shared_ptr<Cat>> vecShared;
    auto sharedCat = make_shared<Cat>();

    vecShared.emplace_back(sharedCat);
    vecShared.emplace_back(sharedCat);

    cout << "reference count : " << sharedCat.use_count() << endl;
    vecShared.erase(vecShared.begin());
    cout << "reference count : " << sharedCat.use_count() << endl;
    vecShared.erase(vecShared.begin());
    cout << "reference count : " << sharedCat.use_count() << endl;

    cout << ">>> shared end!" << endl;
}

void copySharedPtr()
{
    // Do not use like this
    // -------------------------------------
    // Cat* cat = new Cat();
    // shared_ptr<Cat> kitty(cat);
    // cout << "reference count : " << kitty.use_count() << endl;

    // unique_ptr<Cat> nabi(cat);
    // cout << "reference count : " << kitty.use_count() << endl;

    // Use like this
    // -------------------------------------
    // shared_ptr copy
    shared_ptr<Cat> shared_kitty(new Cat());
    shared_ptr<Cat> shared_navi(shared_kitty);
    shared_kitty->print();
    shared_navi->print();

    // unique_ptr move
    unique_ptr<Cat> unique_kitty(new Cat());
    unique_ptr<Cat> unique_navi(move(unique_kitty));
    unique_navi->print();
}


int main()
{
    cout << endl;
    cout << "## call compare_Unique_Shared()" << endl;
    compare_Unique_Shared();

    cout << endl;
    cout << "## call copySharedPtr()" << endl;
    copySharedPtr();

    return 0;
}