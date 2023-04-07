
void merge_sort(int* array, int size)
{
    int middle = 
}

int* merge(int* array1, int size1, int* array2, int size2)
{
    int* merged_array = new int[size1 + size2];

    int iter1 = 0, iter2 = 0;

    while (iter1 < size1 || iter2 < size2)
    {
        if (iter2 >= size2 || array1[iter1] < array2[iter2])
        {
            merged_array[iter1 + iter2] = array1[iter1];
            iter1++;
        }
        else if (iter1 >= size1 || array1[iter1] > array2[iter2])
        {
            merged_array[iter1 + iter2] = array2[iter2];
            iter2++;
        }
    }

    return merged_array;
}