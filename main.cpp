#include <iostream>
#include <string>

using namespace std;

#include "btree.h"

int main()
{
    // Creating an instance of the BTree class
    BTree<int> bt; // creating class object of type integer

    try
    {
        // Initializing the tree with a root node containing the value 1
        bt.setRoot(1); // initializing tree, creating a node, and giving it the value 1

        // Initializing a Position object at the root of the tree
        BTree<int>::Position pos = bt.getRoot(); // initializing Position pos at the root of the tree

        // Adding left and right child nodes to the root
        bt.setLeft(pos, 2);  // setting root's left child value
        bt.setRight(pos, 3); // setting root's right child value

        // Moving to the left child of the current position
        pos = pos.left();

        // Adding left and right child nodes to the current position
        bt.setLeft(pos, 4);
        bt.setRight(pos, 5);

        // Navigating in the tree: moving one level up, then to the right child
        pos = pos.parent().right(); // navigating in the tree: go one up, then go to the right child

        // Adding left and right child nodes to the current position
        bt.setLeft(pos, 6);
        bt.setRight(pos, 7);

        // Printing the value of the root node
        std::cout << "Root: " << (*bt.getRoot()) << std::endl; // print root value

        // Checking if the current position is external and printing the result
        std::cout << "External: " << (pos.isExternal()) << std::endl; // print whether the current position is external

        // Printing the size of the tree
        std::cout << "Size: " << bt.size() << std::endl; // print the size of the tree

        // Printing whether the tree is empty
        std::cout << "Empty: " << bt.empty() << std::endl; // print whether the tree is empty

        // Adding new lines for better readability
        std::cout << std::endl;
        std::cout << "Print Tree:" << std::endl;

        // Printing the tree structure
        bt.print(); // print the tree

        // Adding a new line for better formatting
        std::cout << std::endl;
    }
    catch (const TreeExcept &ex)
    {
        // Handling and printing tree-related exceptions
        std::cerr << "Tree Exception: " << ex.what() << std::endl;
    }

    return 0;
} // main
