
#pragma once

// simple_search - функция поиска с линейным временем
// возвращает индекс элемента или -1, если элемента нет.
unsigned long simple_search(unsigned long* array, unsigned long size, unsigned long key)
{
    for (unsigned long i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}