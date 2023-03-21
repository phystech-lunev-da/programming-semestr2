
#include "find_max_sum.h"

#include <fstream>
#include <iostream>
#include <algorithm>

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

    int x1 = rand() % size;
    int x2 = rand() % size;
    int key = array[x1] + array[x2];

    std::cout << "key: " << key << std::endl;
    int* result = max_sum_simple(array, size, key);
    if (result != nullptr)
        std::cout << "simple sum: " << result[0] << ", " << result[1] << std::endl;
    else
        std::cout << "simple sum: " << "nothing" << std::endl;
    delete[] result;
    result = nullptr;

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

    std::cout << "key: " << key << std::endl;
    result = max_sum_linear(array, size, key);
    if (result == nullptr)
        std::cout << "linear sum: nothing";
    else
        std::cout << "linear sum: " << result[0] << ", " << result[1] << std::endl;

    delete[] result;
    result = nullptr;

    return 0;
}