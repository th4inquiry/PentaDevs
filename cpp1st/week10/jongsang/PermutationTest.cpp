#include "PermutationTest.h"
#include <vector>
#include <iostream>
#include <algorithm>

void PermutationTest::testPermutation()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto printPermutation = [](std::vector<int>& vec, 
                            std::vector<int>::iterator first,
                            std::vector<int>::iterator end) 
    {
        int count = 0;
        do
        {
            std::cout << "{ ";
            for (const auto& elem : vec)
            {
                std::cout << elem << ", ";
            }
            std::cout << "}" << std::endl;

            ++count;
            if (count == 23)
                break;

        } while (std::next_permutation(first, end));

        std::cout << "total count : " << count << std::endl;
        std::cout << "vector address : " << std::addressof(vec) << std::endl;
        };

    std::vector<int> vecInt {4, 1, 2, 3};
    //std::sort(vecInt.begin(), vecInt.end());
    std::cout << "vecInt address : " << std::addressof(vecInt) << std::endl;
    printPermutation(vecInt, vecInt.begin(), vecInt.end());

    printPermutation(vecInt, vecInt.begin()+1, vecInt.end()-1);
}
