#include <iostream>

void analyze_pointer(int *ptr)
{
    std::cout << ptr << " : " << *ptr << "\n";
}

int main()
{
    int stackInt = 5;
    analyze_pointer(&stackInt);

    int *heapInt = new int;
    *heapInt = 10;
    analyze_pointer(heapInt);
    delete heapInt;

    return 0;
}
