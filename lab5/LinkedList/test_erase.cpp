
#include <iostream>
#include <iomanip>

#include "LinkedList.h"

int main()
{
    int size = 1000;

    LinkedList* head = create_list(size);

    std::cout << head << std::endl;

    erase_itr(head);

    std::cout << head << std::endl;
    std::cout << head->data << std::endl;
    std::cout << head->next << std::endl;
    std::cout << std::endl;

    head = create_list(size);

    std::cout << head << std::endl;

    erase(head);

    std::cout << head << std::endl;
    std::cout << head->data << std::endl;
    std::cout << head->next << std::endl;

    return 0;
}