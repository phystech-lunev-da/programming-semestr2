
#pragma once

#include <cstdlib>

void swap(unsigned& a, unsigned& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void forward_step(
    unsigned* arr,
    unsigned const begin_idx, 
    unsigned const end_idx
)
{
    for (int i = begin_idx; i < end_idx - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

void backward_step(
    unsigned* arr,
    unsigned const begin_idx,
    unsigned const end_idx
)
{
    for (int i = end_idx - 1; i > begin_idx; i--)
    {
        if(arr[i-1] > arr[i])
        {
            swap(arr[i], arr[i-1]);
        }
    }
}

void shaker_sort(
    unsigned* arr,
    unsigned const begin_idx,
    unsigned const end_idx
)
{
    unsigned first = begin_idx, last = end_idx;

    while (last - first > 1)
    {
        forward_step(arr, first, last);
        last--;
        backward_step(arr, first, last);
        first++;
    }
}

void bubble_sort_with_step(unsigned* arr, unsigned const size, unsigned const step)
{
    for (int i = 0; i + step < size; i++)
    {
        for (int j = 0; j + step < size - i; j += step)
        {
            if (arr[j] > arr[j + step])
            {
                swap(arr[j], arr[j + step]);
            }
        }
    }
}

void rascheska_sort(
    unsigned* arr,
    unsigned const size
)
{
    for (unsigned step = size; step > 0; step /= 2)
    {
        bubble_sort_with_step(arr, size, step);
    }
}

void insertion_sort_with_step(unsigned* arr, unsigned const size, unsigned step)
{
    for (int i = step; i < size; i++)
    {
        for (int j = i; j - step >= 0; j -= step)
        {
            if (arr[j] > arr[j - step])
            {
                swap(arr[j], arr[j - step]);
            }
        }
    }
}

void shell_sort(unsigned* arr, unsigned const size, )
{

}