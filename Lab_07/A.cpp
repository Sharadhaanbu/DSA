#include <iostream>
using namespace std;

#define SIZE 5  // Fixed size of the queue

class Queue {
private:
    int arr[SIZE];  
    int front, rear; 

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) front = 0;  // Set front to 0 if first insertion
        arr[++rear] = value;
        cout << "Inserted: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove element.\n";
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        if (front == rear) { // Reset queue when last element is removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
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
