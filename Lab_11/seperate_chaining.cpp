#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    list<int> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        for (int item : table[index]) {
            if (item == key) {
                cout << "Duplicate key! Insertion not allowed.\n";
                return;
            }
        }
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        for (int item : table[index]) {
            if (item == key) {
                cout << "Element found at index " << index << endl;
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (int item : table[i])
                cout << item << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\nHash Table Menu (Separate Chaining):\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
