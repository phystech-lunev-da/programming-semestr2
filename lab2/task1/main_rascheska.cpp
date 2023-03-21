
#include <fstream>
#include <iostream>
#include "sort_func.h"
#include <cstdlib>
#include <chrono>
#include <limits>
#include <memory>

// for common behaviour of files
#include "settings.h"

int main()
{
    /*int seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    srand(seed);

    unsigned int size = 10;
    unsigned int* array = new unsigned int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (min + max + 1) + min;
    }

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

    rascheska_sort(array, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;*/

    std::ofstream data;

    data.open("data_rascheska.csv");

    if (!data.is_open())
    {
        return -1;
    }

    data << "size" << " " << "time" << " " << "perm" << std::endl;

    std::cout << "rascheska sort: " << std::endl;

    for (int size = 1; size < max_size; size++)
    {
        long permutations;
        auto begin = std::chrono::steady_clock::now();
        for(unsigned cnt = 10000; cnt != 0 ; --cnt)
        {
            unsigned int* array = new unsigned int[size];

            for (int i = 0; i < size; i++)
            {
                array[i] = rand() % (max + min + 1) + min;
            }
        
            permutations = rascheska_sort(array, size);
            delete[] array;
            array = nullptr;
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        data << size << " " << time_span.count() << " " << permutations << std::endl;
        if (size % 10 == 0)
        {
            std::cout << size << " " << time_span.count() << " " << permutations << std::endl;
        }
    }

    data.close();
    
    return 0;
}