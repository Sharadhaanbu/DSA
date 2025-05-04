#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Node structure for the binary tree
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(NULL), right(NULL) {}
};

// BinaryTree class
class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void constructExpressionTree(const string& postfix) {
        stack<TreeNode*> st;

        for (char ch : postfix) {
            if (isalnum(ch)) { // Operand
                st.push(new TreeNode(ch));
            } else { // Operator
                TreeNode* node = new TreeNode(ch);

                if (!st.empty()) {
                    node->right = st.top();
                    st.pop();
                }

                if (!st.empty()) {
                    node->left = st.top();
                    st.pop();
                }

                st.push(node);
            }
        }

        if (!st.empty()) {
            root = st.top();
            st.pop();
        }
    }

    // Preorder traversal
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    // Inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Postorder traversal
    void postorderTraversal(TreeNode* node) {
        if (node == NULL) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinaryTree tree;
    string postfixExpression;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> postfixExpression;
                break;

            case 2:
                tree.constructExpressionTree(postfixExpression);
                cout << "Expression tree constructed successfully.\n";
                break;

            case 3:
                tree.preorder();
                break;

            case 4:
                tree.inorder();
                break;

            case 5:
                tree.postorder();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);
    return 0;
}