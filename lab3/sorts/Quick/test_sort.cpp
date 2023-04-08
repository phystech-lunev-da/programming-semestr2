

#include <iostream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <cmath>

#include "quick_sort.h"

int main()
{
    int size = 1000;

    std::default_random_engine generator(time(NULL));

    int* array = new int[size];

    std::uniform_int_distribution<int> distribution(0, size);

    for (int i = 0; i < size; i++)
    {
        array[i] = distribution(generator);
    }   

    std::cout << "Array: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3 + ceil(log10(size))) << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3 + ceil(log10(size))) << array[i];
    }

    std::cout << std::endl;

    quick_sort(array, size);
    std::cout << "Sorted: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3 + ceil(log10(size))) << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3 + ceil(log10(size))) << array[i];
    }
}