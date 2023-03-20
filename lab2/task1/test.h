
#pragma once

#include <cstdlib>
#include <chrono>
#include <limits>
#include <memory>

unsigned int min = 0;
unsigned int max = std::numeric_limits<unsigned int>::max()/2;

unsigned int* generate_random_array(unsigned size, unsigned min = 0, unsigned max = std::numeric_limits<unsigned>::max() / 2)
{
    unsigned int* array = new unsigned int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max + min + 1) + min;
    }

    return array;
}

int test(int size, void (*sort_function)(unsigned*, unsigned const))
{
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
    {
        unsigned int* array = new unsigned int[size];

        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % (max + min + 1) + min;
        }
    
        sort_function(array, size);
        delete[] array;
        array = nullptr;
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return time_span.count();
}

int test(int size, void (*sort_function)(unsigned*, unsigned const, unsigned const))
{
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
    {
        unsigned* array = generate_random_array(size, min, max);
        sort_function(array, 0, size);
        delete[] array;
        array = nullptr;
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return time_span.count();
}