
#include <algorithm>

long* generate_random_array(long size, long min, long max)
{
    long* array = new long[size];

    for (long i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

long* generate_random_sorted_array(long size, long min, long max)
{
    long* array = generate_random_array(size, min, max);
    std::sort(array, array + size);

    return array;
}