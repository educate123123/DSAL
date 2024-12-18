#include <iostream>
using namespace std;

// Node structure for a Circular Linked List
struct Node 
{
    int data;
    Node* next;
};

// Circular Queue class using Circular Linked List
class CircularQueue 
{
private:
    Node* front;
    Node* rear;
    
public:
    // Constructor to initialize an empty queue
    CircularQueue() 
    {
        front = nullptr;
        rear = nullptr;
    }
    
    // Enqueue operation: Insert an element at the rear of the queue
    void enqueue(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (front == nullptr) 
        {
            // If the queue is empty, both front and rear will point to the new node
            front = newNode;
            rear = newNode;
            newNode->next = front;  // Make it circular
        } 
        else 
        {
            // If the queue is not empty, insert at the rear
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // Make it circular
        }
    }
    
    // Dequeue operation: Remove an element from the front of the queue
    void dequeue() 
    {
        if (front == nullptr) 
        {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return;
        }
        
        // If there is only one element in the queue
        if (front == rear)
        {
            delete front;
            front = nullptr;
            rear = nullptr;
        } 
        else 
        {
            // If there are multiple elements, remove the front element
            Node* temp = front;
            front = front->next;
            rear->next = front;  // Make it circular
            delete temp;
        }
    }
    
    // Display operation: Show all elements in the queue
    void display() 
    {
        if (front == nullptr) 
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        Node* temp = front;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
    
    // Destructor to free memory
    ~CircularQueue() 
    {
        while (front != nullptr) 
        {
            dequeue();
        }
    }
};

int main() 
{
    CircularQueue q;
    
    // Enqueue elements
    cout << "Enqueueing 10, 20, 30, 40" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    cout << "Queue after enqueueing: ";
    q.display();
    
    // Dequeue elements
    cout << "Dequeuing an element." << endl;
    q.dequeue();
    
    cout << "Queue after dequeuing: ";
    q.display();
    
    // Enqueue another element
    cout << "Enqueueing 50" << endl;
    q.enqueue(50);
    
    cout << "Queue after enqueueing 50: ";
    q.display();
    
    return 0;
}
