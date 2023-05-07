
#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
    unsigned long long R = std::pow(10, 7) + 1;

    unsigned long long size;
    std::cin >> size;

    unsigned long long degree;

    unsigned long long multi = 1;

    for (unsigned long long i = 0; i < size; i++)
    {
        std::cin >> degree;
        multi = (multi % R) * ((degree % R + 1) % R) % R;

    }
    
    std::cout << multi << std::endl;

    return 0;
}