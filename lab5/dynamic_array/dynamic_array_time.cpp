
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

#include "dynamic_array.h"

bool is_cstr_equal(const char* str1, const char* str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    unsigned long long adding_size;
    if (argc > 2)
    {
        adding_size = std::atoi(argv[2]); 
    }
    else
    {
        std::cout << "input the adding size: " << std::endl;
        std::cin >> adding_size;
    }

    auto begin = std::chrono::steady_clock::now();

    for (int cnt = 100; cnt >= 0; cnt--)
    {
        DynamicArray array = new_array(1);
        for (long long i = 1; i <= adding_size; i++)
        {
            if (is_cstr_equal(argv[1], "linear"))
            {
                array = push_back_linear(array, i);
            }
            else if (is_cstr_equal(argv[1], "double"))
            {
                array = push_back_double(array, i);
            }
            else if (is_cstr_equal(argv[1], "once"))
            {
                array = push_back_once(array, i);
            }
            else
            {
                return -1;
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    double time_span = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>((end - begin)).count());

    std::cout << adding_size << " " << time_span << std::endl;
    return 0;
}