#include <iostream>
using namespace std;

#define MAX 100

class GraphMatrix{
    int adj[MAX][MAX];
    int vertices;

public:
    GraphMatrix(int v);
    void Insert(int u, int v);
    void Delete(int u, int v);
    void Search(int u, int v);
    void Display();
};

int main(){
    int v,choice, u,w;
    cout << "Enter number of vertices: ";
    cin >> v;

    GraphMatrix graph(v);

    do{
        cout << "1.INSERT\n";
        cout << "2.DELETE\n";
        cout << "3.SEARCH\n";
        cout << "4.DISPLAY\n";
        cout << "5.EXIT\n";
        cout << "Enter the choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter edge(u v): ";
                cin >> u >> w;
                graph.Insert(u,w);
                break;
            case 2:
                cout << "Enter key to remove: ";
                cin >> u >> w;
                graph.Delete(u,w);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> u >> w;
                graph.Search(u,w);
                break;
            case 4:
                graph.Display();
                break;
            case 5:
                cout << "Exiting...\n\n";
                break;
            default:
                printf("Invalid choice!\n\n");
        }
    }while (choice!= 5);
    return 0;
}

GraphMatrix::GraphMatrix(int v)
{
    vertices = v;
    for(int i=0;i<vertices;i++)
        for(int j = 0; j<vertices;j++)
            adj[i][j] = 0;
}

void GraphMatrix::Insert(int u, int v)
{
    if (u>= vertices || v >= vertices || u< 0 || v< 0){
        cout << "Invalid vertex!\n\n";
        return;
    }
    adj[u][v]=1;
    adj[v][u]=1;
    cout<<"\n\n";
}

void GraphMatrix::Delete(int u, int v)
{
    if (u>= vertices || v >= vertices || u< 0 || v< 0){
        cout << "Invalid vertex!\n\n";
        return;
    }
    adj[u][v]=0;
    adj[v][u]=0;
    cout<<"\n\n";
}

void GraphMatrix::Search(int u, int v)
{
    if (u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout << "Invalid vertex!\n\n";
        return;
    }
    if (adj[u][v])
        cout<< "Edge exists.\n\n";
    else
        cout << "Edge does not exist.\n\n";
}

void GraphMatrix::Display()
{
    for(int i=0;i<vertices;i++){
        for(int j = 0; j<vertices;j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    cout<<"\n\n";
}
