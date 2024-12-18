#include <iostream>
#include <algorithm> // For max function
using namespace std;

// Structure for a node in the Binary Search Tree
struct Node 
{
    int data;
    Node* left;
    Node* right;
    
    Node(int value) 
    {
        data = value;
        left = right = nullptr;
    }
};

// Class for Binary Search Tree
class BST 
{
private:
    Node* root;

public:
    // Constructor to initialize an empty BST
    BST() 
    {
        root = nullptr;
    }

    // Insert a node into the BST
    void insert(int value) 
    {
        root = insertRecursive(root, value);
    }

    // Search for a node in the BST
    bool search(int value) 
    {
        return searchRecursive(root, value);
    }

    // Display the depth (height) of the tree
    int depth() 
    {
        return depthRecursive(root);
    }

    // Display all leaf nodes
    void displayLeafNodes() 
    {
        displayLeafNodesRecursive(root);
    }

    // Function to display the tree (in-order traversal)
    void display()
    {
        inOrderTraversal(root);
        cout << endl;
    }

private:
    // Recursive insert function
    Node* insertRecursive(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }
        if (value < node->data) 
        {
            node->left = insertRecursive(node->left, value);
        } 
        else if (value > node->data) 
        {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    // Recursive search function
    bool searchRecursive(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return false;
        }
        if (node->data == value) 
        {
            return true;
        } else if (value < node->data) 
        {
            return searchRecursive(node->left, value);
        } 
        else 
        {
            return searchRecursive(node->right, value);
        }
    }

    // Recursive function to calculate the depth (height) of the tree
    int depthRecursive(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        int leftDepth = depthRecursive(node->left);
        int rightDepth = depthRecursive(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // Recursive function to display leaf nodes
    void displayLeafNodesRecursive(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        // If it's a leaf node, display it
        if (node->left == nullptr && node->right == nullptr) 
        {
            cout << node->data << " ";
        }
        displayLeafNodesRecursive(node->left);
        displayLeafNodesRecursive(node->right);
    }

    // In-order traversal to display tree elements
    void inOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
};

int main() 
{
    BST tree;

    // Insert elements into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Display the tree (in-order traversal)
    cout << "In-order traversal of the tree: ";
    tree.display();

    // Search for elements
    int searchValue = 40;
    if (tree.search(searchValue)) 
    {
        cout << "Element " << searchValue << " found in the tree." << endl;
    } 
    else 
    {
        cout << "Element " << searchValue << " not found in the tree." << endl;
    }

    // Display the depth (height) of the tree
    cout << "Depth of the tree: " << tree.depth() << endl;

    // Display leaf nodes
    cout << "Leaf nodes of the tree: ";
    tree.displayLeafNodes();
    cout << endl;

    return 0;
}
