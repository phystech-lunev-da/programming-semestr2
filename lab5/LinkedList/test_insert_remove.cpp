
#include <iostream>
#include <iomanip>

#include "LinkedList.h"

int main()
{
    int size = 10;

    LinkedList* head = create_list();
    head->data = 0;

    LinkedList* element = head;

    for (int i = 1; i < size; i++)
    {
        element = insert_after(element);
        element->data = i;
    }

    display_linked_list(head);

    element = head;

    for (int i = 0; i < size / 2 - 1; i++)
    {
        element = element->next;
    }

    remove_after(element);

    display_linked_list(head);   

    element = insert_after(element);
    element->data = 20;

    display_linked_list(head);

    element = head;

    while (element->next != nullptr)
    {
        element = element->next;
    }

    element = head;

    while (element->next->next != nullptr)
    {
        element = element->next;
    }

    remove_after(element);

    display_linked_list(head);

    return 0;
}