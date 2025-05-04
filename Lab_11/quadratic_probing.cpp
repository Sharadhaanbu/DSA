#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

// Initialize table with -1 (empty)
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1 || hashTable[newIndex] == -999) {
            hashTable[newIndex] = key;
            cout << "Inserted " << key << " at index " << newIndex << endl;
            return;
        }
        if (hashTable[newIndex] == key) {
            cout << "Duplicate key! Insertion not allowed.\n";
            return;
        }
        i++;
    }
    cout << "Hash table is full! Insertion failed.\n";
}

void remove(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) break;

        if (hashTable[newIndex] == key) {
            hashTable[newIndex] = -999; // Mark as deleted
            cout << "Deleted " << key << " from index " << newIndex << endl;
            return;
        }
        i++;
    }
    cout << "Element not found!\n";
}

void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) break;

        if (hashTable[newIndex] == key) {
            cout << "Element found at index " << newIndex << endl;
            return;
        }
        i++;
    }
    cout << "Element not found!\n";
}

void display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << ": [Empty]\n";
        else if (hashTable[i] == -999)
            cout << i << ": [Deleted]\n";
        else
            cout << i << ": " << hashTable[i] << endl;
    }
}

int main() {
    initialize();
    int choice, key;

    while (true) {
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
