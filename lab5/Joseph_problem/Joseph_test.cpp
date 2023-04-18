
#include <iostream>

#include "Joseph_algorithm.h"

int main(int argc, char** argv)
{
    int size, step;

    std::cin >> size >> step;

    int result = joseph_buffer(size, step);

    std::cout << result << std::endl;

    result = joseph_array(size, step);

    std::cout << result << std::endl;

    return 0;
}