
#pragma once

// simple_search - функция поиска с линейным временем
// возвращает индекс элемента или -1, если элемента нет.
long simple_search(long* array, long size, long key)
{
    for (long i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}