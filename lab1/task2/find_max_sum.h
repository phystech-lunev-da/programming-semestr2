
#pragma once

#include <cstdlib>
#include <limits>
#include <cstdio>
#include <cstdlib>

#include <chrono>

int* max_sum_simple(int* array, int size, int key)
{
    int* result = new int[2]{-1, -1};
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (key == array[i] + array[j])
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}

int* max_sum_linear(int* arr, int size, int key)
{
    int first_index = 0, last_index = size - 1;

    while (first_index < last_index)
    {
        if (arr[first_index] + arr[last_index] > key)
        {
            last_index--;
        }
        else if (arr[first_index] + arr[last_index] < key)
        {
            first_index++;
        }
        else
        {
            int* result = new int[2];
            result[0] = first_index;
            result[1] = last_index;

            return result;
        }
    }
    return nullptr;
}

int* generate_random_array(int size, int min, int max)
{
    int * array = new int[size];

    for (long i = 0; i < size; i++)
    {
        array[i] = rand() % (-min + max + 1) + min;
    }

    return array;
}

int test(int size, int* (*algorithm)(int*, int, int))
{
    int start_cnt = 100;
    const int min = 1;
    const int max = 10000;
    
    auto begin = std::chrono::steady_clock::now();
    for (int cnt = start_cnt; cnt >= 0; cnt--)
    {
        int* array = generate_random_array(size, min, max);
        int key = rand() % (2 * max - 2 * min + 1) + 2 * min;
        int* result = algorithm(array, size, key);
        delete[] result;
        delete[] array;
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return time_span.count();
}