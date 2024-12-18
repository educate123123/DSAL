#include <iostream>
#include <string>
using namespace std;

// Structure for a node in the linked list
struct Node 
{
    char data;
    Node* next;
};

// Stack class implemented using singly linked list
class Stack 
{
public:
    Node* top;
    
    // Constructor to initialize an empty stack
    Stack() 
    {
        top = nullptr;
    }
    
    // Push an element onto the stack
    void push(char value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    
    // Pop an element from the stack
    char pop() 
    {
        if (top == nullptr) 
        {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    
    // Peek at the top element of the stack
    char peek() 
    {
        if (top == nullptr) 
        {
            return '\0';
        }
        return top->data;
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    
    // Destructor to delete the stack and free memory
    ~Stack() 
    {
        while (top != nullptr) 
        {
            pop();
        }
    }
};

// Function to check if a character is an operator
bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of operators
int precedence(char op) 
{
    if (op == '+' || op == '-') 
    {
        return 1;
    }
    if (op == '*' || op == '/') 
    {
        
        return 2;
    }
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) 
{
    Stack s;
    string postfix = "";
    
    for (char c : infix) 
    {
        if (isalnum(c)) 
        {
            postfix += c;  // Add operand to postfix
        }
        else if (c == '(') 
        {
            s.push(c);  // Push '(' to stack
        }
        else if (c == ')') 
        {
            while (!s.isEmpty() && s.peek() != '(') 
            {
                postfix += s.pop();  // Pop until '(' is found
            }
            s.pop();  // Pop '('
        }
        else if (isOperator(c)) 
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) 
            {
                postfix += s.pop();  // Pop operators with higher or equal precedence
            }
            s.push(c);  // Push current operator to stack
        }
    }
    
    // Pop all remaining operators from the stack
    while (!s.isEmpty()) 
    {
        postfix += s.pop();
    }
    
    return postfix;
}

int main() 
{
    string infix = "A+B*(C-D)";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
