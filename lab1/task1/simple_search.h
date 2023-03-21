
#pragma once

// simple_search - функция поиска с линейным временем
// возвращает индекс элемента или -1, если элемента нет.
int simple_search(int* array, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}