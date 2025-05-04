#include <iostream>
using namespace std;

// Node structure for the linked list queue
struct Node {
    int data;
    Node* next;
};

// Queue class implementing linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) { // If queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove element.\n";
            return;
        }

        Node* temp = front;
        cout << "Removed: " << front->data << endl;
        front = front->next;

        if (front == nullptr) { // If queue becomes empty
            rear = nullptr;
        }

        delete temp;
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to execute menu-driven queue operations
int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}