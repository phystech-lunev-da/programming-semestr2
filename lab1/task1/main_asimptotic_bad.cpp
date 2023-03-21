
#include "binary_search.h"
#include "simple_search.h"
#include <random>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <fstream>

#include "generate_random_arrays.h"

int min = 1;
int max = std::numeric_limits<int>::max() / 2;

int main() { 
    std::ofstream file;

    file.open("data_binary_bad.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "binary search bad" << std::endl;

    int cnt = 20000;

    for (int size = 10000; size < 1000000; size += 1000) {
        int* array = generate_random_sorted_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < cnt; j++) {
            int key = 0;
            binary_search(array, size, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/cnt).count();
        
        file << size << " " << time_span << std::endl;

        if (size % 10000 == 0)
        {
            std::cout << size << " " << time_span << std::endl;
        }

        delete[] array;
    }

    file.close();

    file.open("data_simple_bad.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "simple search bad" << std::endl;

    cnt = 200;

    for (int size = 10000; size < 1000000; size += 1000) {
        int* array = generate_random_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < cnt; j++) {
            int key = 0;
            simple_search(array, size, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/cnt).count();
        
        file << size << " " << time_span << std::endl;

        if (size % 10000 == 0)
        {
            std::cout << size << " " << time_span << std::endl;
        }

        delete[] array;
    }

    file.close();

    return 0;
}