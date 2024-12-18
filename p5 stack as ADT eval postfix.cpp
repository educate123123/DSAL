#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Structure for a node in the linked list
struct Node 
{
    int data;
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
    void push(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    
    // Pop an element from the stack
    int pop() 
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    
    // Peek at the top element of the stack
    int peek() 
    {
        if (top == nullptr)
        {
            return -1;
        }
        return top->data;
    }
    
    // Check if the stack is empty
    bool isEmpty() 
    {
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

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) 
{
    Stack s;
    
    for (char c : postfix) 
    {
        // If character is a digit (operand)
        if (isdigit(c)) 
        {
            s.push(c - '0');  // Convert character to integer and push onto stack
        }
        else if (isOperator(c)) 
        {
            // Pop two operands from the stack
            int operand2 = s.pop();
            int operand1 = s.pop();
            
            // Apply the operator and push the result back onto the stack
            switch (c) 
            {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    
    // The result is the only element left in the stack
    return s.pop();
}

int main() 
{
    string postfix = "23*45*+";
    cout << "Postfix Expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;
    return 0;
}
