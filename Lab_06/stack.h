#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack();
    void push(char val);
    char pop();
    char peek();
    bool isEmpty();
    void display();
};