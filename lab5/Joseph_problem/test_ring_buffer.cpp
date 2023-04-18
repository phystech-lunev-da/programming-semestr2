
#include <iostream>
#include <iomanip>

#include "ring_buffer.h"

int main()
{
    int size = 10;

    LinkedList* ring_buffer = create_ring_buffer(size);

    LinkedList* element = ring_buffer;

    for (int i = 0; i < size; i++)
    {
        element->data = i;
        element = element->next;
    }

    element = ring_buffer;

    for (int i = 0; i < 5 * size; i++)
    {
        std::cout << std::setw(3) << i << ":" << std::setw(3) << element->data << std::endl;
        element = element->next;
    }

    return 0;
}