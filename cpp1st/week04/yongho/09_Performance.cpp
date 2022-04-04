#include <iostream>
#include <chrono>
#include <memory>

int main()
{
    //std::chrono::duration<double> st = std::chrono::system_clock::now();
    auto start = std::chrono::steady_clock::now();

    for (long long i = 0 ; i < 100000000 ; ++i) //1억번
    {
        //int* tmp(new int(i));
        //delete tmp; //6.98779 s , 6.6910 s 

        //std::unique_ptr<int> tmp(new int(i)); //11.7006 s, 12.1482 s
        //std::unique_ptr<int> tmp = std::make_unique<int>(i); //12.0492 s, 12.4975 s
        //std::shared_ptr<int> tmp(new int(i)); //17.6352 s, 16.9795 s
        std::shared_ptr<int> tmp = std::make_shared<int>(i); //26.3204 s, 22.9537 s
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds = end - start;

    //auto dur = std::chrono::system_clock::now() - st();

    std::cout << "elasped time: " << elasped_seconds.count() << " s\n";

    return 0;
}