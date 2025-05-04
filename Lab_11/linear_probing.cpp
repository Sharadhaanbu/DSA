#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

// Initialize all slots to -1 (indicating empty)
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != -1 && hashTable[index] != -999) {
        if (hashTable[index] == key) {
            cout << "Duplicate key! Insertion not allowed.\n";
            return;
        }
        i++;
        index = (originalIndex + i) % SIZE;
        if (i == SIZE) {
            cout << "Hash table is full!\n";
            return;
        }
    }
    hashTable[index] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}

void remove(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            hashTable[index] = -999; // Deleted marker
            cout << "Deleted " << key << " from index " << index << endl;
            return;
        }
        i++;
        index = (originalIndex + i) % SIZE;
        if (i == SIZE) break;
    }
    cout << "Element not found!\n";
}

void search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            cout << "Element found at index " << index << endl;
            return;
        }
        i++;
        index = (originalIndex + i) % SIZE;
        if (i == SIZE) break;
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