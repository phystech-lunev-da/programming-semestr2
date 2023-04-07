
#include <iostream>
#include <iomanip>
#include <random>
#include "merge_sort.h"

int main()
{
    int size1 = 10;
    int size2 = 5;

    int* array1 = new int[size1];
    int* array2 = new int[size2];

    srand(time(NULL));

    array1[0] = rand() % 10;
    array2[0] = rand() % 10;

    for (int i = 1; i < size1; i++)
    {
        array1[i] = rand() % 10 + array1[i - 1];
    }

    for (int i = 1; i < size2; i++)
    {
        array2[i] = rand() % 10 + array2[i - 1];
    }

    std::cout << "First array: " << std::endl;

    for (int i = 0; i < size1; i++)
    {
        std::cout << std::setw(4) << array1[i];
    }
    std::cout << std::endl;

    std::cout << "Second array: " << std::endl;
    for (int i = 0; i < size2; i++)
    {
        std::cout << std::setw(4) << array2[i];
    }
    std::cout << std::endl;

    std::cout << "Merged" << std::endl;
    int* merged = merge(array1, size1, array2, size2);

    for(int i = 0; i < size1 + size2; i++)
    {
        std::cout << std::setw(4) << merged[i];
    }
    std::cout << std::endl;

    return 0;
}