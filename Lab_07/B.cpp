#include <iostream>
using namespace std;

#define SIZE 5  // Fixed size of the queue

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) front = 0;  // Set front to 0 if first insertion
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
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
            front = (front + 1) % SIZE;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function to execute menu-driven queue operations
int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
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
