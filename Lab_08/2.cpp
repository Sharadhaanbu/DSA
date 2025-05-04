#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node in the binary tree
Node* insert(Node* root, char value) {
    if (!root) return new Node(value);
    char choice;
    cout << "Insert " << value << " to left (L) or right (R) of " << root->data << "? ";
    cin >> choice;
    if (choice == 'L' || choice == 'l')
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Function to search for a character in the tree
bool search(Node* root, char key) {
    if (!root) return false;
    if (root->data == key) return true;
    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << "\n";
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << "\n";
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << "\n";
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Character found in the tree.\n";
                else
                    cout << "Character not found.\n";
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
