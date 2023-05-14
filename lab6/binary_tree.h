
#pragma once
#include <iostream>

struct binary_tree
{
    binary_tree *left, *right;
    int key;
};

binary_tree* find_node(binary_tree* head, int key)
{
    binary_tree* iter = head;

    while (iter != nullptr)
    {
        if (iter->key > key)
        {
            iter = iter->left;
        }
        else if (iter->key < key)
        {
            iter = iter->right;
        }
        else
        {
            return iter;
        }
    }

    return nullptr;
}

void add_node(binary_tree* source, binary_tree* target)
{
    if (target->key > source->key)
    {
        if (source->left != nullptr)
        {
            add_node(source->left, target);
        }
        else
        {
            source->left = target;
        }
    }
    else if (target->key < source->key)
    {
        if (source->right != nullptr)
        {
            add_node(source->right, target);
        }
        else
        {
            source->right = target;
        }
    }

    return;
}

void add_node(int key, binary_tree* source)
{
    binary_tree* target = new binary_tree{nullptr, nullptr, key};
    add_node(source, target);
}

void display_tree(binary_tree* head, bool ascending = false)
{
    if (head == nullptr)
    {
        return;
    }
    else if (ascending)
    {
        std::cout << "node = " << head->key << std::endl;
        display_tree(head->left);
        display_tree(head->right);
    }
    else
    {
        display_tree(head->left);
        display_tree(head->right);
        std::cout << "node = " << head->key << std::endl;
    }
}