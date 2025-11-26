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
const int MIN_CHOICE = 1;
const int MAX_CHOICE = 5;

// Function prototypes
void displayMenu();
void readData(IntBinaryTree& tree, string path);
void addNode(IntBinaryTree& tree);
void deleteNode(IntBinaryTree& tree);

// Main function
int main()
{
    // Create a Binary Tree
    IntBinaryTree tree;

    // Read the data
    string path = DATA_FILE;
    readData(tree, path);

    // Create an integer to store user's choice
    int choice;

    while (true)
    {
        // Display the menu
        displayMenu();

        // Prompt the user to enter the choice
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore(1000, 10);

        // Validate the input
        while (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            // Display an error message
            cout << "Error! Invalid choice!" << endl;
            
            // Prompt the user to enter a new choice
            cout << "Enter a new choice (1-5): ";
            cin >> choice;
            cin.ignore(1000, 10);
        }

        // Switch cases
        switch (choice)
        {
            // Add a Node
            case 1:
            {
                // Call the addNode() function
                addNode(tree);

                break;
            }

            // Delete a Node
            case 2:
            {
                // Call the deleteNode() function
                deleteNode(tree);

                break;
            }

            // Exit
            case 5:
            {
                // Display a message
                cout << "Thank you for using the program! Exiting..." << endl;

                // Exit the program
                return 0;
            }
        }
    }

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
    if (str.empty())
    {
        // Display an error message
        cout << "Error! The string must not be empty!" << endl;

        // Prompt the user to enter a new string
        cout << "Please enter a new string: ";
        cin >> str;
        cin.ignore(1000, 10);
    }
    else
    {
        // Otherwise, insert the node to the tree
        tree.insertNode(str);

        // Display a message
        cout << str << " added to the Binary Tree!" << endl;
    }
}

/*
    deleteNode()
    Delete a Node form the Binary Tree
    Arguments:
        - tree: the tree to delete from
    Return: none
*/
void deleteNode(IntBinaryTree& tree)
{
    // Create a string variable to store the Node
    string str;

    // Prompt the user to enter a string to delete
    cout << "Please enter the Node you want to delete: ";
    cin >> str;
    cin.ignore(1000, 10);

    // Check whether the input was empty
    while (str.empty())
    {
        // Display an error message
        cout << "Error! The string must not be empty!" << endl;

        // Prompt the user to enter a new string
        cout << "Please enter a new string: ";
        cin >> str;
        cin.ignore(1000, 10);
    }

    // Search for the Node in the tree
    if (tree.searchNode(str))
    {
        // If the Node is found, we delete it from the tree
        tree.remove(str);

        // Display a message
        cout << str << " is deleted from the Binary Tree!" << endl;
    }
    else
    {
        // Otherwise, we display a message
        cout << str << " does not exist in the tree!" << endl;
    }
}

/*
    searchNode()
    Search for a Node in the tree
*/