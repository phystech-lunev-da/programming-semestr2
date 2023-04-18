

#include <iostream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <cmath>

#include "quick_sort.h"

int main()
{
    int size = 10000;

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

    std::cout << std::endl;

    bool is_sorted = true;
    
    for (int i = 0; i < size - 1; i++)
    {
        is_sorted = is_sorted && (array[i] <= array[i + 1]);
    }

    if (is_sorted)
    {
        std::cout << "array is sorted" << std::endl;
    }
    else
    {
        std::cout << "array is not sorted" << std::endl;
    }

    delete[] array;
}