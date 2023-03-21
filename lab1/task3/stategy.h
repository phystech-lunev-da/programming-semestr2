
#include <algorithm>

void strategy_A(int* array, int size, int index)
{
    std::swap(array[index], array[0]);
}

void strategy_B(int* array, int size, int index)
{
    if (index != 0)
    {
        std::swap(array[index], array[index - 1]);
    }
}