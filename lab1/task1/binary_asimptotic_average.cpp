
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

    file.open("data_binary_average.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "binary search average" << std::endl;

    long cnt = 1000l;

    for (long size = 10000L; size < 1000000L; size += 1000L) {

        long* array = generate_random_sorted_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (long j = 0; j < cnt; j++) {
            long key = array[rand() % size];
            binary_search(array, size, key);
        }
        auto end = std::chrono::steady_clock::now();
        double time_span = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>((end - begin)).count()) ;
        
        file << size << " " << time_span << std::endl;

        delete[] array;
    }

    file.close();

    return 0;
}