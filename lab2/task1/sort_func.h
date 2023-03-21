
#pragma once

#include <cstdlib>
#include <cmath>
#include <vector>

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

long bubble_sort_with_step(unsigned* arr, unsigned const size, unsigned const step)
{
    long permutations = 0;
    for (int i = 0; i + step < size; i++)
    {
        for (int j = 0; j + step < size - i; j += step)
        {
            if (arr[j] > arr[j + step])
            {
                swap(arr[j], arr[j + step]);
                permutations++;
            }
        }
    }

    return permutations;
}

long rascheska_sort(
    unsigned* arr,
    unsigned const size
)
{
    long permutations = 0;
    for (unsigned step = size; step > 0; step /= 2)
    {
        permutations += bubble_sort_with_step(arr, size, step);
    }

    return permutations;
}

void insertion_sort_with_step(unsigned* arr, unsigned const size, unsigned step)
{
    for (int i = 0; i + step < size; i++)
    {
        for (int j = i - step; j >= 0; j -= step)
        {
            if (arr[j + step] < arr[j])
            {
                swap(arr[j + step], arr[j]);
            }
        }
    }
}

std::vector<unsigned> get_geometry_numbers(unsigned n)
{
    std::vector<unsigned> geometry_numbers(n);

    unsigned d = n;
    for (int i = 0; i < n; i++)
    {
        geometry_numbers[i] = d;
        if (d > 1)
        {
            d /= 2;
        }
    }

    return geometry_numbers;
}

std::vector<unsigned> get_fibonacchi_numbers(unsigned n)
{
    std::vector<unsigned> fibonacchi_numbers(0);
    fibonacchi_numbers.push_back(1);
    fibonacchi_numbers.push_back(1);

    while (fibonacchi_numbers[fibonacchi_numbers.size() - 1] + fibonacchi_numbers[fibonacchi_numbers.size() - 2] <= n)
    {
        unsigned size = fibonacchi_numbers.size();
        fibonacchi_numbers.push_back(fibonacchi_numbers[size - 1] + fibonacchi_numbers[size - 2]);
    }
    
    return fibonacchi_numbers;
}

std::vector<unsigned> get_hibbar_numbers(unsigned n)
{
    unsigned max_index = floor(log2(n + 1));
    std::vector<unsigned> hibbar_numbers(max_index - 1);

    for (int i = 0; i < max_index - 1; i++)
    {
        hibbar_numbers[i] = pow(2, i + 1) - 1;
    }

    return hibbar_numbers;
}

void shell_sort_with_geometry(unsigned* arr, unsigned const size)
{
    std::vector<unsigned> geometry = get_geometry_numbers(size);

    for (int i = 0; i < size; i++)
    {
        insertion_sort_with_step(arr, size, geometry[i]);
    }
}

void shell_sort_with_hibbar(unsigned* arr, unsigned const size)
{
    std::vector<unsigned> hibbar = get_hibbar_numbers(size);

    for (int i = hibbar.size() - 1; i >= 0; i--)
    {
        insertion_sort_with_step(arr, size, hibbar[i]);
    }
}

void shell_sort_with_fibonacchi(unsigned* arr, unsigned const size)
{
    std::vector<unsigned> fibonacchi = get_fibonacchi_numbers(size);

    for (int i = fibonacchi.size() - 1; i >= 0; i--)
    {
        insertion_sort_with_step(arr, size, fibonacchi[i]);
    }
}