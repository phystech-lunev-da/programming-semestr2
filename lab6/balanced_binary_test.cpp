
#include "balanced_binary_tree.h"
#include <iostream>

int main()
{
    // rotate test

    balanced_binary_tree* tree = new balanced_binary_tree{nullptr, nullptr, 10};
    add_node(8, tree);
    add_node(6, tree);
    add_node(7, tree);

    display_tree(tree);

    tree = right_rotate(tree);
    std::cout << std::endl;

    display_tree(tree);

    tree = erase(tree);

    return 0;

    //balancing

    // balanced_binary_tree* tree = new balanced_binary_tree{nullptr, nullptr, 20};
    // add_node(19, tree);
    // add_node(15, tree);
    // add_node(30, tree);
    // add_node(16, tree);
    // add_node(31, tree);
    // add_node(28, tree);
    // add_node(17, tree);
    // add_node(14, tree);

    // display_tree(tree);

    // tree = right_rotate(tree);

    // std::cout << "right_rotate: " << std::endl;

    // display_tree(tree);

    // delete tree;
    // return 0;
}