
#include "find_max_sum.h"

#include <fstream>
#include <iostream>

#include <algorithm>


int main()
{
    long seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    int start_cnt = 1000;
    int min = 1;
    int max = 10000;

    srand(seed);
    std::ofstream file;

    file.open("data_simple.csv");

    if (!file.is_open())
    {
        std::cout << "Some error" << std::endl;
        return -1;
    }

    std::cout << "simple algorithm" << std::endl;

    file << "size" << " " << time << std::endl;

    for (long size = 100; size < 10000; size += 100)
    {
        int* array = generate_random_array(size, min, max);
        auto begin = std::chrono::steady_clock::now();
        for (int cnt = start_cnt; cnt >= 0; cnt--)
        {
            int key = 2 * max + 10;
            int* result = max_sum_simple(array, size, key);
            delete[] result;
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>((end - begin)).count();

        delete[] array;

        file << size << " " << time_span << std::endl;
    }

    file.close();

    file.open("data_linear.csv");

    if (!file.is_open())
    {
        std::cout << "Some error" << std::endl;
        return -1;
    }

    std::cout << "linear algorithm" << std::endl;

    file << "size" << " " << time << std::endl;

    start_cnt = 100;

    for (long size = 100; size < 100000; size += 100)
    {    
        int* array = generate_random_array(size, min, max);
        std::sort(array, array + size);
        auto begin = std::chrono::steady_clock::now();    
        for (int cnt = start_cnt; cnt >= 0; cnt--)
        {
            int key = max + min + 10;
            int* result = max_sum_linear(array, size, key);
            delete[] result;
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)).count();

        delete[] array;

        file << size << " " << time_span << std::endl;
    }

    file.close();
    
    std::cout << "Program is finished. \a" << std::endl;
}