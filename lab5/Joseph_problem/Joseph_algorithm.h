
#pragma once

#include <iostream>
#include "ring_buffer.h"

LinkedList* create_units(int size)
{
    LinkedList* units = create_ring_buffer(size);
    LinkedList* element = units;

    for (int i = 0; i < size; i++)
    {
        element->data = i;
        element = element->next;
    }

    return units;
}

int joseph_buffer(int size, int step)
{
    LinkedList* units = create_units(size);

    int cur_size = size;

    /*LinkedList* element = units;
    for (int i = 0; i < cur_size; i++)
    {
        std::cout << " " << element->data;
        element = element->next;
    }
    std::cout << std::endl;*/

    while(cur_size > 1)
    {
        for (int i = 0; i < step - 2; i++)
        {
            units = units->next;
        }
        units = remove_after(units);
        cur_size--;

        /*LinkedList* element = units;
        for (int i = 0; i < cur_size; i++)
        {
            std::cout << " " << element->data;
            element = element->next;
        }

        std::cout << std::endl;*/
    }

    int result = units->data;

    delete units;

    return result;
}

int joseph_array(int size, int step)
{
    int* units = new int[size];

    for (int i = 0; i < size; i++)
    {
        units[i] = i;
    }

    int cur_size = size;

    int index = 0;

    while(cur_size > 1)
    {
        index = (index + step - 1) % cur_size;

        for (int i = index; i < cur_size - 1; i++)
        {
            units[i] = units[i + 1];
        }
        cur_size--;
    }

    int result = units[0];

    delete[] units;

    return result;
}