
#include "find_max_sum.h"

#include <fstream>
#include <iostream>


int main()
{
    long seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    srand(seed);
    std::ofstream file;

    file.open("data_simple.csv");

    if (!file.is_open())
    {
        std::cout << "Some error" << std::endl;
        return -1;
    }

    for (long size = 10000; size < 1000000; size += 10000)
    {
        file << size << "\t" << test(size, max_sum_simple) << std::endl;
    }

    file.close();
    
    std::cout << "Program is finished. \a" << std::endl;
}