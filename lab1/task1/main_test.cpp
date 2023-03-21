
#include "binary_search.h"
#include "simple_search.h"
#include <random>
#include <cstdlib>
#include <limits>
#include <iostream>

#include "generate_random_arrays.h"

int main()
{
    srand(time(NULL));

    int min = -10;
    int max = 10;

    int size = 10;

    int* array = generate_random_array(size, min, max);

    for (int i = 0; i < size; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;

    int key = rand() % (max - min + 1) + min;

    std::cout << "key: " << key << std::endl;
    std::cout << "simple search: " << simple_search(array, size, key) << std::endl;

    std::sort(array, array + size);
    std::cout << "Sorted: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "binary search: " << binary_search(array, size, key) << std::endl;

    return 0;
}