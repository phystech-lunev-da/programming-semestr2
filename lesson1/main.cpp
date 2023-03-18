
#include <iostream>
#include <cstdlib>
#include <cmath>

int evklid(int a, int b)
{
    int r;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool is_simple(int a)
{
    bool b_is_simple = true;
    for (int i = 2; i*i <= (a); i++)
    {
        b_is_simple = a % i != 0;
    }
    return b_is_simple;
}

int main()
{
    std::cout << evklid(3, 5) << std::endl;
    std::cout << evklid(5, 3) << std::endl;
    std::cout << evklid(5, 15) << std::endl;
    std::cout << evklid(15, 15) << std::endl;

    std::cout << std::boolalpha << is_simple(5) << std::noboolalpha << std::endl;
    std::cout << (is_simple(8) ? "true" : "false") << std::endl;
}