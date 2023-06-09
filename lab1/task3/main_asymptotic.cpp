#include "../task1/binary_search.h"
#include "../task1/simple_search.h"
#include "../task1/generate_random_arrays.h"
#include <random>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <fstream>

int min = std::numeric_limits<int>::min() / 2;
int max = std::numeric_limits<int>::max() / 2;

int main() { 
    std::ofstream file;

    file.open("data_simple_average.csv");
    
    if (!file.is_open())
    {
        return 1;
    }
    file << "size" << " " << "time" << std::endl;

    std::cout << "simple search average" << std::endl;

    int cnt = 200;

    for (int size = 10000; size < 1000000; size += 1000) {
        int* array = generate_random_array(size, min, max); 
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < cnt; j++) {
            int key = array[rand() % size];
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