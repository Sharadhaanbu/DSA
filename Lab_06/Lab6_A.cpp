#include <iostream>

#define SIZE 5

using namespace std;

class Stack {
private:
    char arr[SIZE];
    int top;

public:
    Stack();       // Constructor
    void push(char element);
    void pop();
    void peek();
};

// Constructor definition
Stack::Stack() {
    top = -1;
}

// Push operation definition
void Stack::push(char element) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << element << endl;
        return;
    }
    arr[++top] = element;
    cout << element << " pushed into the stack.\n";
}

// Pop operation definition
void Stack::pop() {
    if (top == -1) {
        cout << "Stack Underflow! No elements to pop.\n";
        return;
    }
    cout << "Popped element: " << arr[top--] << endl;
}

// Peek operation definition
void Stack::peek() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}

int main() {
    Stack s;
    int choice;
    char element;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> element;
                s.push(element);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
