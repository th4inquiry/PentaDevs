// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LexiconCompare.h"
#include "PermutationTest.h"
#include "SortingTest.h"
#include "NonModifySequenceTest.h"

using namespace std;

int main()
{
    LexiconCompare lexiconCompare;
    lexiconCompare.testLexiconCompare();

    PermutationTest permutationTest;
    permutationTest.testPermutation();

    SortingTest sortingTest;
    sortingTest.testSortCppref();
    sortingTest.testSort();
    sortingTest.testPartialSort();
    sortingTest.testNthElement();

    NonModifySequenceTest nonModifySeqTest;
    nonModifySeqTest.testAllAnyNoneOf();
    nonModifySeqTest.testForEach();
    nonModifySeqTest.testFindFirstOf();
}

