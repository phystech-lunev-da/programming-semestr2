
#include <algorithm>

int* generate_random_array(int size, int min, int max)
{
    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

int* generate_random_sorted_array(int size, int min, int max)
{
    int* array = generate_random_array(size, min, max);
    std::sort(array, array + size);

    return array;
}