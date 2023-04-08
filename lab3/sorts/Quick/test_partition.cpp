
#include <iostream>
#include <cstdlib>
#include <random>
#include <iomanip>

#include "quick_sort.h"

int main()
{
    int size = 10;

    std::default_random_engine generator(time(NULL));

    int* array = new int[10];

    std::uniform_int_distribution<int> distribution(0, size);

    for (int i = 0; i < size; i++)
    {
        array[i] = distribution(generator);
    }   

    std::cout << "Array: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }

    std::cout << std::endl;

    int middle = partition(array, size);
    std::cout << "Partition by index: " << middle << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << array[i];
    }
}