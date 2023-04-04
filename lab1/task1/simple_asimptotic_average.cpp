
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

long min = std::numeric_limits<long>::min() / 2;
long max = std::numeric_limits<long>::max() / 2;

int main() { 
    std::ofstream file;

    file.open("data_simple_average.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "simple search average" << std::endl;

    long cnt = 1000;

    for (long size = 100; size < 100000; size += 1000) {
        long* array = generate_random_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < cnt; j++) {
            long key = array[rand() % size];
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