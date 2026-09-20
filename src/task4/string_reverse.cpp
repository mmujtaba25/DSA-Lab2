#include <iostream>
#include <string>

namespace util
{
    void swap(char &a, char &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    int floor(double value) { return (int)value; }

    void debug_print(const char *str, int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            // print ":" for NULL byte
            if (str[i] == '\0')
                std::cout << ":";

            std::cout << str[i];
        }
        std::cout << "\n";
    }
}

int main()
{
    constexpr int SIZE = 11;
    char *str = new char[SIZE];

    // fill string with 0
    for (size_t i = 0; i < SIZE; i++)
    {
        str[i] = '\0'; // fill with null bytes
    }

    std::cout << "Enter a string (max " << SIZE - 1 << " chars): ";
    std::cin >> str;

    util::debug_print(str, SIZE);

    std::cout << "\n:MIRRORING: \n\n";

    // mirror string
    for (size_t i = 0; i < util::floor(SIZE / 2); i++)
    {
        util::swap(str[i], str[SIZE - i - 1]);
        util::debug_print(str, SIZE);
    }

    // move string left until first str[0] is not NULL

    // find index of first character not NULL
    int first_not_null = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        if (str[i] != '\0')
        {
            first_not_null = i;
            break;
        }
    }

    std::cout << "\n:" << first_not_null << ":OFFSETTING: \n\n";

    // start at first not NULL; offset each by first_not_null
    for (size_t i = 0; i < SIZE - first_not_null; i++)
    {
        util::swap(str[i], str[i + first_not_null]);
        util::debug_print(str, SIZE);
    }

    std::cout << str;

    return 0;
}
