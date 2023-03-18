
#pragma once

#include <cstdlib>
#include <limits>
#include <cstdio>

#include <chrono>

long* max_sum_simple(long size, long* array, long key)
{
    long sum = std::numeric_limits<long>::min();

    long* result = new long[2]{-1, -1};
    for (long i = 0; i < size; i++)
    {
        for (long j = i + 1; j < size; j++)
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

long max_sum_linear(long size, long* array)
{
    long total = 0, tail = 0;
}

long* generate_random_array(long size, long min, long max)
{
    long * array = new long[size];

    for (long i = 0; i < size; i++)
    {
        array[i] = rand() % (min + max + 1) + min;
    }

    return array;
}

long test(long size, long (*algorithm)(long, long*))
{
    long start_cnt = 1000000;

    long* array = generate_random_array(size, 1, 100000);
    
    auto begin = std::chrono::steady_clock::now();
    for (long cnt = start_cnt; cnt >= 0; cnt--)
    {
        long result = algorithm(size, array);
    }
    auto end = std::chrono::steady_clock::now();
    
    delete[] array;

    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return time_span.count();
}