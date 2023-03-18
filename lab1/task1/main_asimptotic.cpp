
#include <fstream>
#include <iostream>
#include <chrono>

#include "search_test.h"

#include "binary_search.h"
#include "simple_search.h"

bool open_data_file(std::ofstream& file, const char* file_name)
{
    file.open(file_name);
    return file.is_open();
}

int main(int argc, char **argv)
{
    auto seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    srand(seed);
    std::ofstream file;

    const int min_num = 0;
    const int max_num = 2000000;

    const int start_simple_size = 100;
    const int max_simple_size = 100000;
    const int simple_iteration = 1000;

    const int start_binary_size = 1000;
    const int max_binary_size = 100000;
    const int binary_iteration = 1000;

    try
    {
        if(!open_data_file(file, "data_simple.csv"))
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout << "Something is going wrong with file. Program is finished." << std::endl;
        return -1;
    }

    for (auto size = start_simple_size; size < max_simple_size; size += simple_iteration)
    {
        file << size << "\t" << search_test(size, min_num, max_num, simple_search, simple_iteration, generate_random_array) << std::endl;
    }

    std::cout << "Asimptotic test for simple search finished..." << std::endl;

    file.close();

    try
    {
        if(!open_data_file(file, "data_binary.csv"))
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout << "Something is going wrong with file. Program is finished." << std::endl;
        return -1;
    }

    for (auto size = start_binary_size; size < max_binary_size; size += binary_iteration)
    {
        file << size << "\t" << search_test(size, min_num, max_num, binary_search, binary_iteration, generate_random_sorted_array) << std::endl;
    }

    std::cout << "Asimptotic test for binary search finished..." << std::endl;

    file.close();

    std::cout << "Program is finished" << std::endl;

    return 0;
}