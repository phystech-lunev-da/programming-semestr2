
#include <iostream>

int* merge(int* array1, int size1, int* array2, int size2)
{
    int* merged_array = new int[size1 + size2];

    int iter1 = 0, iter2 = 0;

    while (iter1 + iter2 < size1 + size2)
    {
        if (iter1 >= size1)
        {
            *(merged_array + iter1 + iter2) = *(array2 + iter2);
            iter2++; 
        }
        else if (iter2 >= size2)
        {
            *(merged_array + iter1 + iter2) = *(array1 + iter1);
            iter1++; 
        }
        else
        {
            if (*(array1 + iter1) <= *(array2 + iter2))
            {
                *(merged_array + iter1 + iter2) = *(array1 + iter1);
                iter1++; 
            }
            else
            {
                *(merged_array + iter1 + iter2) = *(array2 + iter2);
                iter2++; 
            }
        }
    }

    return merged_array;
}

int* merge_sort(int* array, int size)
{
    if (size == 1)
    {
        return array;
    }

    int left_size = size / 2;
    int right_size = size - left_size;

    int* left = merge_sort(array, left_size);
    int* right = merge_sort(array + left_size, right_size);

    int* merged = merge(left, left_size, right, right_size);

    for (int i = 0; i < size; i++)
    {
        array[i] = merged[i];
    }

    delete[] merged;

    return array;
}