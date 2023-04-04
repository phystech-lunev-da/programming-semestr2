
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

long min = 1;
long max = std::numeric_limits<long>::max() / 2;

int main() { 
    std::ofstream file;

    file.open("data_binary_bad.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "binary search bad" << std::endl;

    long cnt = 1;

    for (long size = 100l; size < 10000000l; size += 100) {
        long* array = generate_random_sorted_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (long j = 0; j < cnt; j++) {
            int key = max + 10;
            binary_search(array, size, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)).count();
        
        file << size << " " << time_span << std::endl;

        delete[] array;
    }

    file.close();

    return 0;
}