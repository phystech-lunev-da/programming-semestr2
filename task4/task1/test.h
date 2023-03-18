
#include <cstdlib>
#include <chrono>

unsigned* generate_random_array(unsigned size, unsigned min = 0, unsigned max = 4000000)
{
    unsigned* array = new unsigned[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max + min + 1) + min;
    }

    return array;
}

int test(int size, void (*sort_function)(unsigned*, unsigned const, unsigned const))
{
    unsigned min = 0;
    unsigned max = 4000000;

    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
    {
        unsigned* array = generate_random_array(size, min, max);
        sort_function(array, 0, size);
        delete[] array;
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return time_span.count();
}