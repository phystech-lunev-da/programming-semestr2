
#pragma once

#include <iostream>
#include <iomanip>

struct LinkedList
{
    LinkedList* next;
    int data;
};

LinkedList* create_list()
{
    LinkedList* list = new LinkedList;
    list->next = nullptr;

    list->data = 0;

    return list;
}

LinkedList* create_list(int size)
{
    LinkedList* head = create_list();

    LinkedList* element = head;

    for (int i = 0; i < size - 1; i++)
    {
        element->next = create_list();
        element = element->next;
    }

    return head;
}

LinkedList* insert_after(LinkedList * const current)
{
    LinkedList* new_element = create_list();

    if (current != nullptr)
    {
        LinkedList* next_element = current->next;

        current->next = new_element;
        if (next_element != nullptr)
        {
            new_element->next = next_element;
        }
    }

    return new_element;
}

LinkedList* remove_after(LinkedList * const current)
{
    LinkedList* next_element = nullptr;

    if (current != nullptr && current->next != nullptr)
    {
        LinkedList* deleted_element = current->next;
        next_element = deleted_element->next;

        current->next = next_element;

        delete deleted_element;
        deleted_element = nullptr;
    }

    return next_element;
}

void erase(LinkedList** head)
{
    if ((*head)->next != nullptr)
    {
        erase((&(*head)->next));
        (*head)->next = nullptr;
    }

    delete *head;
    *head = nullptr;
    return;
}

LinkedList* reverse_rec(LinkedList* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        return head;
    }

    LinkedList* last = head->next;

    LinkedList* reversed = reverse_rec(last);

    head->next = nullptr;
    last->next = head;
    
    return reversed;
}

LinkedList* reverse_itr(LinkedList* head)
{
    if (head == nullptr)
    {
        return head;
    }

    // содержит голову списка
    LinkedList* prev_element = head;
    LinkedList* element = nullptr;
    LinkedList* next_element = nullptr;

    if (prev_element->next)
    {
        element = prev_element->next;
    }
    else
    {
        return prev_element;
    }

    if (element->next)
    {
        next_element = element->next;
    }
    else
    {
        prev_element->next = nullptr;
        element->next = prev_element;
        return element;
    }

    prev_element->next = nullptr;

    while (next_element)
    {
        element->next = prev_element;
        prev_element = element;
        element = next_element;
        next_element = next_element->next;
    }

    element->next = prev_element;

    return element;
}

void display_linked_list(LinkedList * const head)
{
    LinkedList* element = head;

    while (element != nullptr)
    {
        std::cout << std::setw(3) << element->data;
        element = element->next;
    }

    std::cout << std::endl;
}