#include "binary_tree.h"

int main()
{
    binary_tree* tree = new binary_tree{nullptr, nullptr, 20};
    add_node(19, tree);
    add_node(15, tree);
    add_node(30, tree);
    add_node(16, tree);
    add_node(31, tree);
    add_node(28, tree);
    add_node(17, tree);
    add_node(14, tree);

    std::cout << std::endl;
    display_tree(tree, false);

    // std::cout << std::endl;

    // binary_tree* founded = find_node(tree, 15);

    // if (founded)
    //     std::cout << "node = " << founded->key << std::endl;
    // else
    //     std::cout << "node is not found" << std::endl;

    display_in_right_order(tree, false);

    std::cout << std::endl;

    display_in_right_order(tree, true);

    std::cout << std::endl;

    // display_in_right_order_iter(tree);

    std::cout << std::endl;

    delete tree;
    // delete founded;

    return 0;
}