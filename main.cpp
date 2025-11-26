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
void readData(IntBinaryTree& tree);
void addNode(IntBinaryTree& tree);

// Main function
int main()
{
    // Create a Binary Tree
    IntBinaryTree tree;

    // Read the data
    string path = DATA_FILE;
    readData(tree, path);

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
    cout << " --- Operation Menu --- " << endl;

    // Display all the operations
    cout << "1. Add Node" << endl;
    cout << "2. Delete Note" << endl;
    cout << "3. Search Node" << endl;
    cout << "4. Modify Records" << endl;
    cout << "5. Exit" << endl;
}

/*
    readData()
    Read the data from a file and insert the Nodes into the Binary Tree
    Arguments:
        - tree: the Binary Tree to insert to
        - path: the path of the data file
    Return: none
*/
void readData(IntBinaryTree& tree, string path)
{
    // Create file stream
    ifstream fin;
    fin.open(path);

    // Create a string to store the data
    string line;

    // Read the records
    while (getline(fin, line))
    {
        // Create a Node and add it to the Binary Tree
        tree.insertNode(line);
    }
}

/*
    addNode()
    Add a Node into the Binary Tree
    Arguments:
        - tree: the Binary Tree to insert to
    Return: none
*/
void addNode(IntBinaryTree& tree)
{
    // Create a string variable
    string str;

    // Prompt the user to enter a string
    cout << "Please enter a string to insert: ";
    cin >> str;
    cin.ignore(1000, 10);

    // Check the length of the Node
    if (str.length() == 0)
    {
        // Display an error message
        cout << "Error! The string must not be empty!" << endl;

        // Prompt the user to enter a new string
        cout << "Please enter a new string: ";
        cin >> str;
        cin.ignore(1000, 10);
    }
}