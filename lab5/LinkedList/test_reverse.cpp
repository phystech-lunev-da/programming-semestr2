

#include <iostream>
#include <iomanip>

#include "LinkedList.h"

int main()
{
    int size = 10;

    LinkedList* head = create_list(size);

    LinkedList* element = head;

    int i = 0;

    while(element)
    {
        element->data = i++;
        element = element->next;
    }

    display_linked_list(head);

    head = reverse_itr(head);

    display_linked_list(head);

    head = reverse_rec(head);

    display_linked_list(head);

    return 0;
}