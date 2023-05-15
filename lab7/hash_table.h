
#pragma once

#include <iostream>
#include "../lab5/LinkedList/LinkedList.h"

static int M = 10;

int hash(int n)
{
    return n % M;
}

struct Hash_table
{
    LinkedList** table;
};

Hash_table* create_hash_table()
{
    Hash_table* table = new Hash_table;
    table->table = new LinkedList*[M];

    for (int i = 0; i < M; i++)
    {
        table->table[i] = nullptr;
    }

    return table;
}

void add_element(Hash_table& table, int data)
{
    LinkedList* hash_list = table.table[hash(data)];

    LinkedList* new_elem = create_list();
    new_elem->data = data;

    new_elem->next = hash_list;
    table.table[hash(data)] = new_elem;
}

LinkedList* find_element(Hash_table& table, int data)
{
    LinkedList* hash_list = table.table[hash(data)];
    
    LinkedList* iter = hash_list;

    while (iter != nullptr && iter->data != data)
    {
        iter = iter->next;
    }

    return iter;
}

void delete_element(Hash_table& table, int data)
{
    LinkedList* hash_list = table.table[hash(data)];

    LinkedList* iter = hash_list;

    if (iter->data == data)
    {
        table.table[hash(data)] = table.table[hash(data)]->next;
        delete hash_list;
        return;
    }

    while (iter->next != nullptr && iter->next->data != data)
    {
        iter = iter->next;
    }

    remove_after(iter);

    return;
}

void display(Hash_table& table)
{
    for (int i = 0; i < M; i++)
    {
        std::cout << i << ": ";
        display_linked_list(table.table[i]);
    }
}

void erase_table(Hash_table* table)
{
    for (int i = 0; i < M; i++)
    {
        table->table[i] = erase(table->table[i]);
    }
}