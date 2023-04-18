
#include <utility>

int partition(int* array, int size)
{
    int pivot = size / 2;
    std::swap(*(array + size - 1), *(array + pivot));

    int middle = 0;

    for (int i = 0; i < size - 1; i++)
    {
        if( *(array + i) < *(array + size - 1))
        {
            std::swap(*(array + i), *(array + middle));
            middle++;
        }
    }
    std::swap(*(array + size - 1), *(array + middle));
    return middle;
}

void quick_sort(int* array, int size)
{  
    if (size <= 1)
    {
        return;
    }

    int middle = partition(array, size);

    quick_sort(array, middle);
    quick_sort(array + middle + 1, size - middle - 1);
}