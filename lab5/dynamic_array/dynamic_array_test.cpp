
#include <iostream>
#include <iomanip>
#include "dynamic_array.h"

void display_dynamic_array(DynamicArray& array)
{
    for (unsigned int i = 0; i < array.size; i++)
    {
        std::cout << std::setw(3) << array.elements[i];
    }
    std::cout << std::endl;

    std::cout << "size: " << array.size << ", capacity: " << array.capacity << std::endl;
}

int main()
{
    DynamicArray array = new_array(10, 1);
    display_dynamic_array(array);

    erase(array);

    display_dynamic_array(array);

    array = push_back(array, 2);

    display_dynamic_array(array);

    erase(array);

    for (int i = 0; i < 10; i++)
    {
        array = push_back(array, 2 * i);

        display_dynamic_array(array);
    }

    DynamicArray cloned_array = clone(array);

    display_dynamic_array(array);
    display_dynamic_array(cloned_array);

    cloned_array.elements[5] = 0;

    display_dynamic_array(array);
    display_dynamic_array(cloned_array);

    return 0;
}