#include <iostream>
#include <cassert>

bool isSorted(const int *arr, const int size);
void testSorter();

int main()
{
    testSorter();
}

bool isSorted(const int *arr, const int size)
{
    if (size == 0)
        return false;

    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}

// MARK: TESTS

namespace tests
{
    void testSortedArray()
    {
        int arr[] = {1, 2, 3, 4, 5};
        assert(isSorted(arr, 5) == true);
    }

    void testUnsortedArray()
    {
        int arr[] = {4, 5, 2, 3, 1};
        assert(isSorted(arr, 5) == false);
    }

    void testDuplicateValues()
    {
        int arr[] = {1, 2, 3, 4, 4};
        assert(isSorted(arr, 5) == true);
    }

    void testSingleElement()
    {
        int arr[] = {1};
        assert(isSorted(arr, 1) == true);
    }

    void testDescendingArray()
    {
        int arr[] = {5, 4, 3, 2, 1};
        assert(isSorted(arr, 5) == false);
    }

    void testNegativeValues()
    {
        int arr[] = {-5, -4, -3, -2, -1};
        assert(isSorted(arr, 5) == true);
    }

    void testAllSameValues()
    {
        int arr[] = {1, 1, 1, 1, 1};
        assert(isSorted(arr, 5) == true);
    }

    void testEmptyArray()
    {
        assert(isSorted({}, 0) == false);
    }
}

void testSorter()
{
    tests::testSortedArray();     // 1
    tests::testUnsortedArray();   // 2
    tests::testDuplicateValues(); // 3
    tests::testSingleElement();   // 4
    tests::testDescendingArray(); // 5
    tests::testNegativeValues();  // 6
    tests::testAllSameValues();   // 7
    tests::testEmptyArray();      // 8
}
