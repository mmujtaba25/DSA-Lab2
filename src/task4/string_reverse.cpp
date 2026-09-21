#include <iostream>
#include <string>

constexpr int DEBUG = false;

namespace util
{
    void swap(char &a, char &b);
    int floor(double value);
    void debug_print(const char c);
    void debug_print(const char *str, int size);
}

void reverse_string(char *str, const int size);
void reverse_string_raw(char *str, const int size);

int main()
{
    constexpr int SIZE = DEBUG ? 11 : 51; // one extra for NULL byte
    char *str = new char[SIZE];

    std::cout << "Enter a string (max " << SIZE - 1 << " chars): ";
    std::cin.getline(str, SIZE);

    reverse_string(str, SIZE);

    std::cout << "Your string is reverse is: " << str << "\n\n";
    delete[] str;

    return 0;
}

namespace util
{
    void swap(char &a, char &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    int floor(double value) { return (int)value; }

    void debug_print(const char c)
    {
        if (!DEBUG)
            return;

        // print ":" for NULL byte
        if (c == '\0')
            std::cout << ":";

        std::cout << c;
    }

    void debug_print(const char *str, int size)
    {
        if (!DEBUG)
            return;

        for (size_t i = 0; i < size; i++)
            debug_print(str[i]);

        std::cout << "\n";
    }
}

void reverse_string_raw(char *str, const int size)
{
    util::debug_print(str, size);

    if (DEBUG)
        std::cout << "\n:MIRRORING: \n\n";

    // mirror string
    for (size_t i = 0; i < util::floor(size / 2); i++)
    {
        util::swap(str[i], str[size - i - 1]);
        util::debug_print(str, size);
    }
}

void reverse_string(char *str, const int size)
{
    reverse_string_raw(str, size);

    // get first null character from the right
    // first null from right is where cout terminates
    int null_at = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (str[i] == '\0')
        {
            null_at = i + 1;
            break;
        }
    }

    if (DEBUG)
        std::cout << "\n:OFFSETTING: \n\n";
    util::debug_print(str, size);

    // move string so str[0] is the last character before first character
    for (size_t i = 0; i < (size - null_at); i++)
    {
        util::swap(str[i], str[i + null_at]);
        util::debug_print(str, size);
    }

    // append NULL at string end (before str[0] in original string)
    str[size - null_at] = '\0';

    util::debug_print(str, size);
}
