// sequential container

#include <iostream>
#include <array>
#include <vector>
#include <deque>

using namespace std;

class Person
{
public:
    Person() = delete;
    explicit Person(int age, string nationality, string nickName) : 
        myAge(age), myNationality(nationality), myNickName(nickName) {}

    void print()
    {
        cout << "Age : " << myAge << ", Nationality : " << myNationality << ", NickName : " << myNickName << endl;
    }

private:
    int myAge;
    string myNationality;
    string myNickName;
};

// function to return the iterator type
template <class T>
string get_iterator_type(T it)
{
    const type_info& typeInfo = typeid(typename iterator_traits<T>::iterator_category);
    return typeInfo.name();
}

int main()
{
    Person baby(4, "USA", "Nick");
    Person teenager(12, "China", "Wang");
    Person adult(30, "Korea", "Kim");

    // array
    array<Person, 3> array { baby, teenager, adult };

    cout << "------------------" << endl;
    auto arrayIt = array.begin();
    cout << "array iterator category : " << get_iterator_type(arrayIt) << endl;

    for(auto person : array)
    {
        person.print();
    }

    // vector
    vector<Person> vec;
    vec.reserve(100);
    vec.push_back(baby);
    vec.emplace_back(teenager);
    vec.emplace_back(std::move(adult));
    Person& grandfather = vec.emplace_back(70, "Japan", "Shin");

    cout << "------------------" << endl;
    auto vecIt = vec.begin();
    cout << "vector iterator category : " << get_iterator_type(vecIt) << endl;
    cout << "vector capacity : " << vec.capacity() << ", size : " << vec.size() << ", max size : " << vec.max_size() << endl;

    for(auto person : vec)
    {
        person.print();
    }

    // deque
    deque<Person> deq;
    deq.emplace_back(baby);
    deq.emplace_back(teenager);
    deq.emplace_front(70, "Japan", "Shin");

    cout << "------------------" << endl;
    auto deqIt = deq.begin();
    cout << "deque iterator category : " << get_iterator_type(deqIt) << endl;

    for(auto person : deq)
    {
        person.print();
    }

    return 0;
}
