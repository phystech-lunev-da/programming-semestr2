
#pragma once

#include <chrono>
#include <cstdlib>
#include <algorithm>

unsigned long* generate_random_array(unsigned long size, unsigned long min, unsigned long max)
{
    unsigned long* array = new unsigned long[size];
    for (unsigned long i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }
    return array;
}

unsigned long* generate_random_sorted_array(unsigned long size, unsigned long min, unsigned long max)
{
    unsigned long* array = generate_random_array(size, min, max);
    std::sort(array, array + size, [](unsigned long a, unsigned long b){return a <= b;});
    return array;
}

unsigned long search_test(
    unsigned long size, 
    unsigned long min, 
    unsigned long max, 
    unsigned long (*search_function)(unsigned long*, unsigned long, unsigned long), 
    unsigned long start_cnt, 
    unsigned long* (*generate_array_function)(unsigned long, unsigned long, unsigned long)
)
{
    auto* array = generate_array_function(size, min, max);
    
    auto begin = std::chrono::steady_clock::now();
    for (auto cnt = start_cnt; cnt >= 0; cnt--)
    {
        auto key = array[rand() % size];
        auto result = search_function(array, size, key);
    }
    auto end = std::chrono::steady_clock::now();
    
    delete[] array;

    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return time_span.count();
}