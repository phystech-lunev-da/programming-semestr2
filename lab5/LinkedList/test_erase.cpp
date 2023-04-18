
#include <iostream>
#include <iomanip>

#include "LinkedList.h"

int main()
{
    int size = 10;

    LinkedList* head = create_list(10);

    display_linked_list(head);

    erase(&head);

    LinkedList* element = head;

    while (element != nullptr)
    {
        std::cout << std::setw(3) << element->data;
        element = element->next;
    }
    std::cout << std::endl;

    if (head)
    {
        std::cout << "head is not nullptr" << std::endl;
    }
    else
    {
        std::cout << "head is nullptr" << std::endl;
    }

    return 0;
}