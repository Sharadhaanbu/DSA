#include <iostream>

using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

class List
{
private:
    node* head;

public:
    List() { head = NULL; }

    int Insert_beginning(int num);
    int Insert_pos(int num, int pos);
    int Insert_end(int num);
    int Delete_begining();
    int Delete_position(int pos);
    int Delete_end();
    int Search(int num);
    void Display();
    int count();
};

List dll; // Creating a global instance of the list

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

    if (head == NULL)
    {
        newnode->next = newnode->prev = newnode;
        head = newnode;
        return 1;
    }

    node* tail = head->prev;

    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    head = newnode;

    return 1;
}

// Insert at a Position
int List::Insert_pos(int num, int pos)
{
    if (pos < 1 || pos > count() + 1)
    {
        cout << "The position is out of range.\n";
        return 0;
    }
    if (pos == 1)
        return Insert_beginning(num);
    if (pos == count() + 1)
        return Insert_end(num);

    node* newnode = new node();
    newnode->data = num;

    node* temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    return 1;
}

// Insert at End
int List::Insert_end(int num)
{
    if (head == NULL)
        return Insert_beginning(num);

    node* newnode = new node();
    newnode->data = num;

    node* tail = head->prev;

    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;

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

    node* tail = head->prev;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return 1;
    }

    node* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;

    delete temp;
    return 1;
}

// Delete from a Position
int List::Delete_position(int pos)
{
    if (pos < 1 || pos > count())
    {
        cout << "The position is out of range.\n";
        return 0;
    }
    if (pos == 1)
        return Delete_begining();
    if (pos == count())
        return Delete_end();

    node* temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    node* delNode = temp->next;
    temp->next = delNode->next;
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

    node* tail = head->prev;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return 1;
    }

    node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;

    delete tail;
    return 1;
}

// Search for an Element
int List::Search(int num)
{
    node* temp = head;
    if (temp == NULL)
        return 0;

    do
    {
        if (temp->data == num)
            return 1;
        temp = temp->next;
    } while (temp != head);

    return 0;
}

// Display List
void List::Display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    do
    {
        cout << "->" << temp->data;
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Count number of elements
int List::count()
{
    if (head == NULL)
        return 0;

    int count = 0;
    node* temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}
