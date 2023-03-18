
#include "search_test.h"
#include "binary_search.h"
#include <iostream>
#include <ctime>
#include <limits>

int main()
{
    srand(time(NULL));

    unsigned long size = 10000000l;

    unsigned long* array = generate_random_sorted_array(size, 0, std::numeric_limits<unsigned long>::max());
    
    // for (unsigned long i = 0; i < 10; i++)
    // {
    //     std::cout << i << "\t";
    // }
    // std::cout << std::endl;
    // for (unsigned long i = 0; i < 10; i++)
    // {
    //     std::cout << array[i] << "\t";
    // }
    // std::cout << std::endl;

    unsigned long pos = binary_search(array, size, std::numeric_limits<unsigned long>::max()/2);

    std::cout << "5 on the position: " << pos << std::endl;

    delete[] array;

    return 0;
}
