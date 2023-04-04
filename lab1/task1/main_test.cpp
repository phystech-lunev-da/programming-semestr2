
#include "binary_search.h"
#include "simple_search.h"
#include <random>
#include <cstdlib>
#include <limits>
#include <iostream>

#include "generate_random_arrays.h"

int main()
{
    srand(time(NULL));

    long min = -100;
    long max = 100;

    long size = 100;

    long right_answers = 100;

    for (long i = 0; i < 100; i++)
    {
        long* array = generate_random_sorted_array(size, min, max);


        long key = rand() % (max - min + 1) + min;

        long simple_result = simple_search(array, size, key);

        long binary_result = binary_search(array, size, key);

        if (array[binary_result] != array[simple_result])
        {
            for (long i = 0; i < size; i++)
            {
                std::cout << i << "\t";
            }
            std::cout << std::endl;
            for (long i = 0; i < size; i++)
            {
                std::cout << array[i] << "\t";
            }
            std::cout << std::endl;

            std::cout << "key: " << key << std::endl;

            std::cout << "simple search: index = " << simple_result << ", value = " << array[simple_result] << std::endl;

            std::cout << "binary search: index = " << binary_result << ", value = " << array[binary_result] << std::endl;

            right_answers--;
        }

        delete[] array;

    }

    std::cout << "There are " << right_answers << " right answers." << std::endl;


    return 0;
}