
#pragma once

// бинарный поиск
long binary_search(long* array, long size, long key)
{
    unsigned long left = 0, right = size - 1, middle;
    
    while ((left <= right) && (right < size))
    {
        middle = left + (right - left) / 2;

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
    return -1;
}