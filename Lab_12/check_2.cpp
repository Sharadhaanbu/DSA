#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int vertex;
};

class GraphList {
public:
    int vertices;
    Node** adjList;

    GraphList(int v);
    void Insert(int u, int v);
    void Delete(int u, int v);
    void Search(int u, int v);
    void Display();
};

int main() {
    int v, choice, u, w;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    GraphList graph(v);

    while (1) {
        cout<<"\nTHE MENU:\n1. INSERT\n2. DELETE\n3. SEARCH\n4. DISPLAY\n5. EXIT\n";
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter vertices u and v: ";
                cin>>u>>w;
                graph.Insert(u, w);
                break;
            case 4:
                cout<<"\nDisplaying Graph:\n";
                graph.Display();
                break;
            case 3:
                cout<<"Enter vertices u and v to search: ";
                cin>>u>>w;
                graph.Search(u, w);
                break;
            case 2:
                cout<<"Enter vertices u and v to delete the edge: ";
                cin>>u>>w;
                graph.Delete(u, w);
                break;
            case 5:
                cout<<"\nExiting the program !!\n";
                exit(0);
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

GraphList::GraphList(int v)
{
    vertices = v;
    adjList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
}

void GraphList::Insert(int u, int v)
{
    if (u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout<<"Invalid vertices\n";
        return;
    }
    Node* newnode1 = (Node*)malloc(sizeof(Node));
    newnode1->vertex = v;
    newnode1->next = adjList[u];
    adjList[u] = newnode1;

    Node* newnode2 = (Node*)malloc(sizeof(Node));
    newnode2->vertex = u;
    newnode2->next = adjList[v];
    adjList[v] = newnode2;

    cout<<"Successfully Inserted Edge between " <<u <<" and " <<v <<endl;
}

void GraphList::Delete(int u, int v)
{
    if (u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout<<"Invalid vertices\n";
        return;
    }

    Node *curr = adjList[u], *prev = NULL;
    while (curr != NULL && curr->vertex != v) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout<<"No edge found between " <<u <<" and " <<v <<"deleted" <<endl;
    } else {
        if (prev == NULL) {
            adjList[u] = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        cout<<"Edge between " <<u <<" and " <<v <<"deleted" <<endl;
    }

    curr = adjList[v];
    prev = NULL;
    while (curr != NULL && curr->vertex != u) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout<<"No edge found between " <<u <<" and " <<v <<endl;
    } else {
        if (prev == NULL) {
            adjList[v] = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        cout<<"Edge between " <<u <<" and " <<v <<"deleted" <<endl;
    }
}

void GraphList::Search(int u, int v)
{
    if (u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout<<"Invalid vertices\n";
        return;
    }

    Node* curr = adjList[u];
    while (curr != NULL) {
        if (curr->vertex == v) {
            cout<<"Edge exists between " <<u <<" and " <<v <<endl;
            return;
        }
        curr = curr->next;
    }
    cout<<"There exists no edge between " <<u <<" and " <<v <<endl;
}

void GraphList::Display()
{
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d", i);
        Node* curr = adjList[i];
        while (curr != NULL) {
            printf(" -> %d", curr->vertex);
            curr = curr->next;
        }
        cout<< endl;
    }
}
