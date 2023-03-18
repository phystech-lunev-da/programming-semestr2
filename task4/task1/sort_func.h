
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

void rasheska_sort(
    unsigned* arr,
    unsigned const begin_idx,
    unsigned const end_idx
)
{
    for (unsigned step = end_idx - begin_idx; step > 0; step / 2)
    {
        for (int i = begin_idx; i < end_idx; i += step)
        {
            for (int j = begin_idx; j < end_idx - i + begin_idx; j += step)
            {
                if (arr[j] > arr[j + step])
                {
                    swap(arr[i], arr[i + step]);
                }
            }
        }
    }
}