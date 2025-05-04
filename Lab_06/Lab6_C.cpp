#include "stack.h"

Stack::Stack() {
    top = nullptr;
}

void Stack::push(char val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!\n";
        return '\0';
    }
    char val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

char Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return '\0';
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }
    Node* temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack s;
    int choice;
    char value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << "Popped: " << s.pop() << endl;
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}