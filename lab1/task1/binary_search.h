
#pragma once

// бинарный поиск
int binary_search(int* array, int size, int key)
{
    int left = 0, right = size, middle;
    
    while (left <= right)
    {
        middle = (left + right) / 2;

        if (array[middle] < key)
        {
            left = middle + 1;
        }
        else if (array[middle] > key)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }
    }
    if ((left <= -1) || (right >= size) || (array[left] != key))
    {
        return -1;
    }
    return left;
}