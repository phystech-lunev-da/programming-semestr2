
#include <fstream>
#include <iostream>
#include "sort_func.h"
#include "test.h"

int main()
{

    int seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    srand(seed);

    /*std::ofstream data;

    data.open("data.csv");

    if (!data.is_open())
    {
        return -1;
    }

    data << "size" << " " << "time" << std::endl;

    for (int size = 1; size < 100; size++)
    {
        int time = test(size, shaker_sort);
        std::cout << size << " " << time << std::endl;
        data << size << " " << time << std::endl;
    }*/

    unsigned* array = generate_random_array(10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;

    rasheska_sort(array, 2, 8);

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    
    return 0;
}