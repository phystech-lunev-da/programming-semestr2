
#pragma once
#include "../LinkedList/LinkedList.h"

LinkedList* create_ring_buffer(int size)
{
    LinkedList* head = create_list(size);

    LinkedList* last = head;

    while (last->next)
    {
        last = last->next;
    }

    last->next = head;

    return head;
}