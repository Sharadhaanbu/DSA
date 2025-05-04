#include <iostream>

// Creating class
class btree {
public:
    struct node {
        int data;
        struct node* Lchild;
        struct node* Rchild;
    };

private:
    struct node* root;

public:
    btree();
    int Insert(int num);
    void Preorder(node* temp);
    void Inorder(node* temp);
    void Postorder(node* temp);
    int Search(int num);
    node* getRoot();
};

btree::btree() {
    root = NULL;
}

btree::node* btree::getRoot() {
    return root;
}

int btree::Insert(int num) {
    struct node* newnode = new node;
    struct node* temp = root;

    newnode->data = num;
    newnode->Lchild = NULL;
    newnode->Rchild = NULL;

    if (root == NULL) {
        root = newnode;
        return 1;
    } else {
        while (temp != NULL) {
            if (num < temp->data) {
                if (temp->Lchild == NULL) {
                    temp->Lchild = newnode;
                    return 1;
                }
                temp = temp->Lchild;
            } else if (num > temp->data) {
                if (temp->Rchild == NULL) {
                    temp->Rchild = newnode;
                    return 1;
                }
                temp = temp->Rchild;
            }
        }
    }
    return 0;
}

void btree::Preorder(node* temp) {
    if (temp == NULL) return;
    printf("%d ", temp->data);
    Preorder(temp->Lchild);
    Preorder(temp->Rchild);
}

void btree::Inorder(node* temp) {
    if (temp == NULL) return;
    Inorder(temp->Lchild);
    printf("%d ", temp->data);
    Inorder(temp->Rchild);
}

void btree::Postorder(node* temp) {
    if (temp == NULL) return;
    Postorder(temp->Lchild);
    Postorder(temp->Rchild);
    printf("%d ", temp->data);
}

int btree::Search(int num) {
    struct node* temp = root;
    if (temp == NULL) {
        printf("The tree is empty!\n");
        return 0;
    }
    while (temp != NULL) {
        if (num == temp->data) return 1;
        if (num < temp->data)
            temp = temp->Lchild;
        else
            temp = temp->Rchild;
    }
    return 0;
}

int main() {
    btree tree;
    btree::node* temp = tree.getRoot(); 
    int choice, num;

    while (1) {
        printf("\n\nMenu:\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to be inserted: ");
                scanf("%d", &num);
                if (tree.Insert(num)) printf("The element is added.\n");
                else printf("Element not added.\n");
                break;
            case 2:
                printf("Preorder: ");
                tree.Preorder(tree.getRoot());
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                tree.Inorder(tree.getRoot());
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                tree.Postorder(tree.getRoot());
                printf("\n");
                break;
            case 5:
                printf("Enter number to be searched: ");
                scanf("%d", &num);
                if (tree.Search(num)) printf("The element is found.\n");
                else printf("Element does not exist.\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}