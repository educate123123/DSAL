#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Structure for a tree node
struct Node 
{
    char data;
    Node* left;
    Node* right;
    
    Node(char value) 
    {
        data = value;
        left = right = nullptr;
    }
};

// Function to check if a character is an operator
bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from a postfix expression
Node* constructPostfixTree(string postfix) 
{
    stack<Node*> s;
    
    for (char c : postfix) 
    {
        if (isdigit(c) || isalpha(c))
        {
            s.push(new Node(c)); // Operand (leaf node)
        } 
        else if (isOperator(c)) 
        {
            Node* node = new Node(c);  // Operator node
            node->right = s.top(); s.pop();  // Right operand
            node->left = s.top(); s.pop();   // Left operand
            s.push(node);
        }
    }
    
    return s.top();  // The root of the expression tree
}

// Function to construct an expression tree from a prefix expression
Node* constructPrefixTree(string prefix) 
{
    stack<Node*> s;
    
    // Traverse the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) 
    {
        char c = prefix[i];
        
        if (isdigit(c) || isalpha(c)) 
        {
            s.push(new Node(c)); // Operand (leaf node)
        } 
        else if (isOperator(c)) 
        {
            Node* node = new Node(c);  // Operator node
            node->left = s.top(); s.pop();  // Left operand
            node->right = s.top(); s.pop(); // Right operand
            s.push(node);
        }
    }
    
    return s.top();  // The root of the expression tree
}

// In-order traversal (Recursive)
void inorder(Node* root) 
{
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal (Recursive)
void preorder(Node* root) 
{
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal (Recursive)
void postorder(Node* root) 
{
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() 
{
    string postfix = "ab+c*";
    string prefix = "*+abcd";
    
    cout << "Constructing expression tree from Postfix: " << postfix << endl;
    Node* rootPostfix = constructPostfixTree(postfix);
    
    cout << "In-order traversal of Postfix tree: ";
    inorder(rootPostfix);
    cout << endl;
    
    cout << "Pre-order traversal of Postfix tree: ";
    preorder(rootPostfix);
    cout << endl;
    
    cout << "Post-order traversal of Postfix tree: ";
    postorder(rootPostfix);
    cout << endl;
    
    cout << "Constructing expression tree from Prefix: " << prefix << endl;
    Node* rootPrefix = constructPrefixTree(prefix);
    
    cout << "In-order traversal of Prefix tree: ";
    inorder(rootPrefix);
    cout << endl;
    
    cout << "Pre-order traversal of Prefix tree: ";
    preorder(rootPrefix);
    cout << endl;
    
    cout << "Post-order traversal of Prefix tree: ";
    postorder(rootPrefix);
    cout << endl;
    
    return 0;
}

