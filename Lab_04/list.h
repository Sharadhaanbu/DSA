#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Class for List ADT
class List {
private:
    Node* head;

    // Private function to get the head pointer
    Node* getHead() { return head; }

public:
    List();  // Constructor
    void insertAscending(int value);  // Insert node in ascending order
    void mergeLists(List& list1, List& list2);  // Merge two lists
    void display();  // Display list
};

// Constructor initializes head
List::List() {
    head = NULL;
}

// Insert in ascending order
void List::insertAscending(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Merge two sorted lists into a third sorted list
void List::mergeLists(List& list1, List& list2) {
    Node* t1 = list1.getHead();
    Node* t2 = list2.getHead();
    head = NULL;
    Node** lastPtr = &head;

    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) {
            *lastPtr = t1;
            t1 = t1->next;
        } else {
            *lastPtr = t2;
            t2 = t2->next;
        }
        lastPtr = &((*lastPtr)->next);
    }

    *lastPtr = (t1 != NULL) ? t1 : t2;
}

// Display the list
void List::display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}