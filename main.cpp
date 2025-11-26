// COMSC-210 | Lab 36 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
    // Create a Binary Tree
    IntBinaryTree tree;
    tree.insertNode("Dat");
    tree.insertNode("Hoang");
    tree.insertNode("Vien");

    // Display the tree
    tree.displayInOrder();

    // Remove a Node
    tree.remove("Dat");

    // Display the tree
    tree.displayPreOrder();

    return 0;
}