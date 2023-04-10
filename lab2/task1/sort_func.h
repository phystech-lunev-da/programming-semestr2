


// файл с сортировочными алгоритмами



#pragma once

#include <cstdlib>
#include <cmath>
#include <vector>


// переставляет элементы
// Можно использовать std::swap
void swap(unsigned& a, unsigned& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

// forward_step - шаг сортировки пузырьком в одну сторону
// часть шейкерной сортировки
// индекс проходит в промежутке [begin_idx, end_idx)
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

// backward_step - шаг сортировки пузырьком в противоположную сторону
// часть шейкерной сортировки
// индекс проходит в промежутке [begin_idx, end_idx)
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


// shaker_sort - шейкерная сортировка. Сортируем сначала в одну, а затем в другую сторону
// индексы пробегают [begin_idx, end_idx)
void shaker_sort(
    unsigned* arr,
    unsigned const begin_idx,
    unsigned const end_idx
)
{
    unsigned first = begin_idx, last = end_idx;

    // пока разность больше единицы (т.е. не пройдем весь массив)
    while (last - first > 1)
    {
        forward_step(arr, first, last);
        last--;
        backward_step(arr, first, last);
        first++;
    }
}


// bubble_sort_with_step - сортируем элементы массива, 
// находящиеся на расстоянии step друг от друга,
// с помощью пузырьковой сортировки
// часть сортировки расческой
long bubble_sort_with_step(unsigned* arr, unsigned const size, unsigned const step)
{
    long permutations = 0;  // число перестановок
    for (int i = 0; i + step < size; i++)
    {
        for (int j = 0; j + step < size - i; j += step)
        {
            // если элементы в неправильном порядке, меняем местами
            if (arr[j] > arr[j + step])
            {
                swap(arr[j], arr[j + step]);
                permutations++;
            }
        }
    }

    return permutations;
}

// сортировка расческой
// по факту сортировка пузырьком с шагом, постепенно уменьшающейся до 1
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


// сортировка вставками с шагом step
// часть сортировки Шелла
void insertion_sort_with_step(unsigned* arr, unsigned const size, unsigned step)
{
    for (int i = 0; i < size; i++)
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

// создает массив шагов, являющихся геометрической прогрессией
// часть соритровки Шелла
std::vector<unsigned> get_geometry_numbers(unsigned size)
{
    std::vector<unsigned> geometry_numbers(size);

    unsigned d = size;
    for (int i = 0; i < size; i++)
    {
        geometry_numbers[i] = d;
        if (d > 1)
        {
            d /= 2;
        }
    }

    return geometry_numbers;
}

// создает массив шагов, являющихся последовательностью Фибоначчи
// часть сортировки Шелла
std::vector<unsigned> get_fibonacchi_numbers(unsigned n)
{
    std::vector<unsigned> fibonacchi_numbers(0);
    fibonacchi_numbers.push_back(1); // push_bak добавляет элемент в массив
    fibonacchi_numbers.push_back(1);

    while (fibonacchi_numbers[fibonacchi_numbers.size() - 1] + fibonacchi_numbers[fibonacchi_numbers.size() - 2] <= n)
    {
        unsigned size = fibonacchi_numbers.size();
        fibonacchi_numbers.push_back(fibonacchi_numbers[size - 1] + fibonacchi_numbers[size - 2]);
    }
    
    return fibonacchi_numbers;
}

// создает массив шагов, являющихся последовательностью чисел Хиббарда (2^i - 1)
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