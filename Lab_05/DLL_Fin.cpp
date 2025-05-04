//Program to perform operations in doubly linked list

#include "DLL.h"

List dll;

int main()
{
    int choice, num, pos;
    while (1)
    {
        cout << "\n\nMenu\n1. Insert Beginning\n2. Insert Position\n3. Insert End\n4. Delete Beginning\n5. Delete Position\n6. Delete End\n7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be inserted at beginning: ";
            cin >> num;
            if (dll.Insert_beginning(num)) { cout << "The Element is added."; }
            else { cout << "Element NOT added."; }
            break;
        case 2:
            cout << "Enter the element to be added: ";
            cin >> num;
            cout << "Enter Position: ";
            cin >> pos;
            if (dll.Insert_pos(num, pos)) { cout << "The Element is added."; }
            else { cout << "Element NOT added."; }
            break;
        case 3:
            cout << "Enter the element to be added at the end: ";
            cin >> num;
            if (dll.Insert_end(num)) { cout << "The Element is added."; }
            else { cout << "Element NOT added."; }
            break;
        case 4:
            if (dll.Delete_begining()) { cout << "The element is deleted."; }
            else { cout << "Element NOT deleted."; }
            break;
        case 5:
            cout << "Enter Position of element to be deleted: ";
            cin >> pos;
            if (dll.Delete_position(pos)) { cout << "The element is deleted."; }
            else { cout << "Element NOT deleted."; }
            break;
        case 6:
            if (dll.Delete_end()) { cout << "The element is deleted."; }
            else { cout << "Element NOT deleted."; }
            break;
        case 7:
            cout << "Enter the element to be searched: ";
            cin >> num;
            if (dll.Search(num)) { cout << "Element is found."; }
            else { cout << "Element was NOT found."; }
            break;
        case 8:
            dll.Display();
            break;
        case 9:
            return 0;
        default:
            cout << "Enter a Valid Input.";
        }
    }
}

// Insert at Beginning
int List::Insert_beginning(int num)
{
    node* newnode = new node();
    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
    return 1;
}

// Insert at a Position
int List::Insert_pos(int num, int pos)
{
    node* newnode = new node();
    newnode->data = num;
    node* temp = head;
    int count = dll.count();

    if (pos > count + 1 || pos < 1)
    {
        cout << "The position is out of range.\n";
        return 0;
    }
    else if (pos == 1)
    {
        return dll.Insert_beginning(num);
    }
    else if (pos == count + 1)
    {
        return dll.Insert_end(num);
    }
    else
    {
        int step = 1;
        while (step < pos - 1)
        {
            temp = temp->next;
            step++;
        }

        newnode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
        newnode->prev = temp;

        return 1;
    }
}

// Insert at End
int List::Insert_end(int num)
{
    node* newnode = new node();
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        return 1;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
    return 1;
}

// Delete from Beginning
int List::Delete_begining()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return 0;
    }

    node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return 1;
}

// Delete from a Position
int List::Delete_position(int pos)
{
    int count = dll.count();
    if (pos > count || pos < 1)
    {
        cout << "The position is out of range.\n";
        return 0;
    }

    if (pos == 1)
        return dll.Delete_begining();

    if (pos == count)
        return dll.Delete_end();

    node* temp = head;
    int step = 1;
    while (step < pos - 1)
    {
        temp = temp->next;
        step++;
    }

    node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL)
        delNode->next->prev = temp;

    delete delNode;
    return 1;
}

// Delete from End
int List::Delete_end()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return 0;
    }

    node* temp = head;

    if (temp->next == NULL)
    {
        delete temp;
        head = NULL;
        return 1;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return 1;
}

// Search for an Element
int List::Search(int num)
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Display List
void List::Display()
{
    node* temp = head;
    if (temp == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Count number of elements
int List::count()
{
    int count = 0;
    node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
