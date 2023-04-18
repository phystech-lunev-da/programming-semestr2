
#include <iostream>
#include <cstdlib>
#include <chrono>

#include "Joseph_algorithm.h"

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
    srand(time(NULL));

    const char * cc_type = argv[1];
    const char * cc_size = argv[2];

    unsigned int size = atoi(cc_size);

    auto begin = std::chrono::steady_clock::now();
    for (int cnt = 1000; cnt >= 0; cnt--)
    {
        int step = rand() % (size / 2 - 2 + 1) + 2;

        if (is_cstr_equal(cc_type, "buffer"))
        {
            joseph_buffer(size, step);
        }
        else if (is_cstr_equal(cc_type, "array"))
        {
            joseph_array(size, step);
        }
        else
        {
            return -1;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto duration_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    std::cout << size << " " << duration_time << std::endl;
}