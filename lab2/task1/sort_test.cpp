
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

#include "sort_func.h"

int main()
{
    unsigned size = 10;
    unsigned max = size * 2;
    unsigned min = 0;

    unsigned* array = new unsigned[size];

    srand(time(NULL));

    for (unsigned i = 0; i < size; i++)
    {
        array[i] = rand() % (max + min + 1) + min;
    }

    std::cout << "Source: " << std::endl;
    for (unsigned i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;

    shell_sort_with_hibbar(array, size);

    std::cout << "Sorted: " << std::endl;
    for (unsigned i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;
}