
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <stack>

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
        if (source->right != nullptr)
        {
            add_node(source->right, target);
            return;
        }
        else
        {
            source->right = target;
        }
    }
    else if (target->key < source->key)
    {
        if (source->left != nullptr)
        {
            add_node(source->left, target);
            return;
        }
        else
        {
            source->left = target;
        }
    }

    return;
}

void add_node(int key, binary_tree* source)
{
    binary_tree* target = new binary_tree{nullptr, nullptr, key};
    add_node(source, target);
}

binary_tree* erase(binary_tree* tree)
{
    if (tree->left != nullptr)
    {
        tree->left = erase(tree->left);
    }
    if (tree->right != nullptr)
    {
        tree->right = erase(tree->right);
    }
    delete tree;
    tree = nullptr;
    return tree;
}

void display_tree(binary_tree* head, bool ascending = false, int moves = 0)
{
    static std::string indent = "--";

    if (!ascending)
    {
        if (head->right != nullptr)
        {
            display_tree(head->right, ascending, moves + 1);
        }
        for (int i = 0; i < moves; i++)
        {
            std::cout << indent;
        }
        std::cout << head->key << "\n";
        if (head->left != nullptr)
        {
            display_tree(head->left, ascending, moves + 1);
        }
    }
    else
    {
        if (head->right != nullptr)
        {
            display_tree(head->right, ascending, moves + 1);
        }
        std::cout << head->key << "\n";
        std::cout << indent;
        if (head->left != nullptr)
        {
            display_tree(head->left, ascending, moves + 1);
        }
    }
}

void display_in_right_order(binary_tree* head, bool ascending = false)
{
    if (head->left == nullptr && head->right == nullptr)
    {
        std::cout << head->key << " ";
        return;
    }
    if (ascending)
    {
        if (head->left != nullptr)
        {
            display_in_right_order(head->left, ascending);
        }
        std::cout << head->key << " ";
        if (head->right != nullptr)
        {
            display_in_right_order(head->right, ascending);
        }
        return;
    }
    else
    {
        if (head->right != nullptr)
        {
            display_in_right_order(head->right, ascending);
        }
        std::cout << head->key << " ";
        if (head->left != nullptr)
        {
            display_in_right_order(head->left, ascending);
        }
        return;
    }
}

void display_in_right_order_iter(binary_tree* tree, bool ascending = false)
{
    std::stack<binary_tree*> bin_tree_stack;

    bin_tree_stack.push(tree);

    while (!bin_tree_stack.empty())
    {
        if (bin_tree_stack.top()->left != nullptr)
        {
            bin_tree_stack.push(bin_tree_stack.top()->left);
            continue;
        }
        binary_tree* temp = bin_tree_stack.top();
        bin_tree_stack.pop();
        std::cout << temp->key << " ";
        if (temp->right != nullptr)
        {
            bin_tree_stack.push(temp->right);
            continue;
        }
    }
}