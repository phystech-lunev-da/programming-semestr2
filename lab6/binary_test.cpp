#include "binary_tree.h"

int main()
{
    binary_tree* tree = new binary_tree{nullptr, nullptr, 20};
    add_node(10, tree);
    add_node(9, tree);
    add_node(15, tree);

    display_tree(tree, true);
    std::cout << std::endl;
    display_tree(tree, false);

    binary_tree* founded = find_node(tree, 15);

    std::cout << "node = " << founded->key << std::endl;

    return 0;
}