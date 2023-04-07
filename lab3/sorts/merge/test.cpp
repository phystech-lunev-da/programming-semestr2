
#include <iostream>
#include <iomanip>
#include <random>
#include "merge_sort.h"

int main()
{
    int size = 100;

    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distribution(0, size);

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = distribution(generator);
    }

    std::cout << "Unsorted array" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;

    merge_sort(array, size);

    std::cout << "Sorted array" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;

}