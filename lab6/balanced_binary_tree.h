#pragma once

#include <iostream>
#include <algorithm>

struct balanced_binary_tree
{
    balanced_binary_tree* left;
    balanced_binary_tree* right;

    int key;

    int left_height;
    int right_height;
};

int height(balanced_binary_tree* tree)
{
    int left_height = tree ? left_height : 0;
    int right_height = tree ? right_height : 0;
    return std::max(left_height, right_height) + 1;
}

void add_node(balanced_binary_tree* source, balanced_binary_tree* target)
{
    if (target->key > source->key)
    {
        if (source->right != nullptr)
        {
            add_node(source->right, target);
            source->right_height = height(source->right);
            return;
        }
        else
        {
            source->right = target;
            source->right_height++;
            return;
        }
    }
    else if (target->key < source->key)
    {
        if (source->left != nullptr)
        {
            add_node(source->left, target);
            source->left_height = height(source->left);
            return;
        }
        else
        {
            source->left = target;
            source->left_height++;
            return;
        }
    }
    else
    {
        delete[] source;
        source = target;
    }

    return;
}

void add_node(int key, balanced_binary_tree* source)
{
    balanced_binary_tree* target = new balanced_binary_tree{nullptr, nullptr, key};
    add_node(source, target);
}

balanced_binary_tree* erase(balanced_binary_tree* tree)
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

void display_tree(balanced_binary_tree* head, bool ascending = false, int moves = 0)
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

balanced_binary_tree* right_rotate(balanced_binary_tree* head)
{
    balanced_binary_tree* root = head;
    balanced_binary_tree* left = head->left;
    balanced_binary_tree* left_right_tree = left->right;

    // обрезали связи
    head->left = nullptr;
    left->right = nullptr;

    // кореной элемент - левое поддерево
    head = left;
    // его правое поддерево - предыдущий головной
    head->right = root;
    // правое поддерево левого поддерева становится левым поддеревом правого
    head->right->left = left_right_tree;

    // обновить высоты поддеревьев
    head->right->left_height = height(head->right->left);
    head->right_height = height(head->right);


    return head;
}

balanced_binary_tree* left_rotate(balanced_binary_tree* head)
{
    balanced_binary_tree* root = head;
    balanced_binary_tree* right = head->right;
    balanced_binary_tree* right_left_tree = right->left;

    head->right = nullptr;
    right->left = nullptr;

    head = right;
    head->left = root;
    head->left->right = right_left_tree;

    head->left->right_height = height(head->left->right);
    head->left_height = height(head->left);

    return head;
}

balanced_binary_tree* balance(balanced_binary_tree* head)
{
    if (head->left == nullptr || head->right == nullptr)
    {
        return head;
    }
    
    head->left = balance(head->left);
    head->right = balance(head->right);

    head->left_height = head->left->left_height + 1;
    head->right_height = head->right->right_height + 1;

    while (head->left_height - head->right_height >= 2)
    {
        head = right_rotate(head);
    }
    while (head->right_height - head->left_height >= 2)
    {
        head = left_rotate(head);
    }

    return head;
}