
#include <iostream>
#include "hash_table.h"

int main()
{
    Hash_table* table = create_hash_table();

    add_element(*table, 0);
    add_element(*table, 10);
    add_element(*table, 1);
    add_element(*table, 2);

    display(*table);

    std::cout << std::endl;

    LinkedList* elem = find_element(*table, 1);

    if (elem == nullptr)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found " << elem->data << std::endl;

    if (elem == nullptr)
        std::cout << "not found" << std::endl;
    else
        elem = find_element(*table, 6);

    if (elem == nullptr)
    {
        std::cout << "not found" << std::endl;
    }

    std::cout << std::endl;

    delete_element(*table, 10);

    display(*table);

    std::cout << std::endl;

    erase_table(table);

    display(*table);

    delete[] table;

    return 0;
}