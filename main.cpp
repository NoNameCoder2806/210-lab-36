// COMSC-210 | Lab 36 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

// Constants
const string DATA_FILE = "codes.txt";

// Function prototypes
void displayMenu();

// Main function
int main()
{
    // Create a Binary Tree
    IntBinaryTree tree;

    // Create file stream
    ifstream fin;
    fin.open(DATA_FILE);

    // Create a string to store the data
    string line;

    // Read the records
    while (getline(fin, line))
    {
        // Create a Node and add it to the Binary Tree
        tree.insertNode(line);
    }

    // Display the tree
    tree.displayInOrder();

    return 0;
}

// Function implementation
/*
    displayMenu()
    Display all the operations to perform on the Binary Tree
    Arguments: none
    Return: none
*/
void displayMenu()
{
    // Display a header
    cout << "";
    
    // Display all the operations
    cout << "1. Add Node" << endl;
    cout << "2. Delete Note" << endl;
    cout << "3. Search Node" << endl;
    cout << "4. Modify Records" << endl;
    cout << "5. Exit" << endl;
}