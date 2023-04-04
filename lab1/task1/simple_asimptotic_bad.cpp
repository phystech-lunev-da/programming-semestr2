
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
long max = std::numeric_limits<int>::max() / 2;

int main() { 
    std::ofstream file;

    file.open("data_simple_bad.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "simple search bad" << std::endl;

    long cnt = 1000;

    for (int size = 100; size < 100000; size += 1000) {
        long* array = generate_random_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (long j = 0; j < cnt; j++) {
            long key = 0;
            simple_search(array, size, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>((end - begin)).count();
        
        file << size << " " << time_span << std::endl;

        delete[] array;
    }

    file.close();

    return 0;
}