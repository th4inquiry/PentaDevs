#include <iostream>
#include <vector>

int main()
{
    std::vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    std::cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        std::cout << *i << " ";

    std::cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        std::cout << *i << " ";

    std::cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        std::cout << *ir << " ";

    std::cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        std::cout << *ir << " ";

    std::vector<int> g2;

    for (int i = 1; i <= 5; i++)
        g2.push_back(i);

    std::cout << "\n\nSize : " << g2.size();
    std::cout << "\nCapacity : " << g2.capacity();
    std::cout << "\nMax_Size : " << g2.max_size();

    //resizes the vector size to 4
    g2.resize(4);

    //prints the vector size after resize()
    std::cout << "\nSize : " << g2.size();

    //checks if the vector is empty or not
    if (g2.empty() == false)
        std::cout << "\nVector is not empty";
    else
        std::cout << "\nVector is empty";

    //Shrinks the vector
    g2.shrink_to_fit();
    std::cout << "\nVector elements are: ";
    for (auto it = g2.begin(); it != g2.end(); it++)
        std::cout << *it << " ";


    std::vector<int> g3;

    for (int i = 1; i <= 10; i++)
        g3.push_back(i * 10);

    std::cout << "\nReference operator [g] : g3[2] = " << g3[2];
    std::cout << "\nat : g3.at(4) = " << g3.at(4);
    std::cout << "\nfront : g3.front() = " << g3.front();
    std::cout << "\nback : g3.back() = " << g3.back();

    //pointer to the first element
    int* pos = g3.data();
    std::cout << "\nThe first element is " << *pos;
    std::cout << "\nThe 3rd element is " << *(pos + 2);


    //Assign vector
    std::vector<int> v;

    //fill the array with 10 five times
    v.assign(5, 10);

    std::cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    //inserts 15 to the last position
    v.push_back(15);
    size_t n = v.size();
    std::cout << "\nThe last element is : " << v[n - 1];

    //removes last element
    v.pop_back();

    //prints the vector
    std::cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    //inserts 5 at the beginning
    v.insert(v.begin(), 5);
    std::cout << "\nThe first element is : " << v[0];

    //remove the first element
    v.erase(v.begin());
    std::cout << "\nThe first element is : " << v[0];

    //inserts at the beginning
    v.emplace(v.begin(), 5);
    std::cout << "\nThe first element is : " << v[0];

    //Inserts 20 at the end
    v.emplace_back(20);
    n = v.size();
    std::cout << "\nThe last element is : " << v[n - 1];

    //erases the vector
    v.clear();
    std::cout << "\nVector size after erase() : " << v.size();

    //two vector to perform swap
    std::vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    std::cout << "\nVector1 is : ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";

    std::cout << "\nVector2 is : ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";

    //Swap v1 and v2
    v1.swap(v2);

    std::cout << "\nAfter Swap \nVector1 is : ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";

    std::cout << "\nVector2 is : ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";

    return 0;
}