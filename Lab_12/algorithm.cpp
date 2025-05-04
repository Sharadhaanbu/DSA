#include <iostream>
using namespace std;

const int MAX = 100;

struct HeapNode {
    int vertex;
    int dist;
};

class MinHeap {
    HeapNode heap[MAX];
    int size;

    void swap(int i, int j) {
        HeapNode temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

public:
    MinHeap() {
        size = 0;
    }

    void push(int vertex, int dist) {
        int i = size++;
        heap[i] = {vertex, dist};
        while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
            swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    HeapNode pop() {
        HeapNode root = heap[0];
        heap[0] = heap[--size];
        int i = 0;
        while (2 * i + 1 < size) {
            int child = 2 * i + 1;
            if (child + 1 < size && heap[child + 1].dist < heap[child].dist)
                child++;
            if (heap[i].dist <= heap[child].dist) break;
            swap(i, child);
            i = child;
        }
        return root;
    }

    bool empty() {
        return size == 0;
    }
};

class Graph {
public:
    int V;
    int cost[MAX][MAX];

    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cost[i][j] = -1;
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || u >= V || v < 0 || v >= V || w < 0) {
            cout << "Invalid edge.\n";
            return;
        }
        cost[u][v] = w;
        cost[v][u] = w;
    }

    void prim() {
        int selected[MAX] = {0}, key[MAX], parent[MAX];
        for (int i = 0; i < V; i++) {
            key[i] = 99999;
            parent[i] = -1;
        }
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!selected[i] && (u == -1 || key[i] < key[u]))
                    u = i;

            selected[u] = 1;

            for (int v = 0; v < V; v++)
                if (cost[u][v] != -1 && !selected[v] && cost[u][v] < key[v]) {
                    key[v] = cost[u][v];
                    parent[v] = u;
                }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << " : " << cost[i][parent[i]] << "\n";
    }

    int findSet(int i, int parent[]) {
        while (i != parent[i])
            i = parent[i];
        return i;
    }

    void kruskal() {
        struct Edge {
            int u, v, w;
        } edges[MAX * MAX];

        int parent[MAX], nEdges = 0;

        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (cost[i][j] != -1)
                    edges[nEdges++] = {i, j, cost[i][j]};

        // Bubble sort
        for (int i = 0; i < nEdges - 1; i++)
            for (int j = 0; j < nEdges - i - 1; j++)
                if (edges[j].w > edges[j + 1].w)
                    swap(edges[j], edges[j + 1]);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        cout << "Kruskal's MST:\n";
        for (int i = 0, count = 0; i < nEdges && count < V - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int set_u = findSet(u, parent);
            int set_v = findSet(v, parent);

            if (set_u != set_v) {
                cout << u << " - " << v << " : " << edges[i].w << "\n";
                parent[set_u] = set_v;
                count++;
            }
        }
    }

    void dijkstra(int src) {
        int dist[MAX], visited[MAX] = {0};
        for (int i = 0; i < V; i++)
            dist[i] = 99999;
        dist[src] = 0;

        MinHeap pq;
        pq.push(src, 0);

        while (!pq.empty()) {
            HeapNode node = pq.pop();
            int u = node.vertex;

            if (visited[u]) continue;
            visited[u] = 1;

            for (int v = 0; v < V; v++) {
                if (cost[u][v] != -1 && !visited[v] && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    pq.push(v, dist[v]);
                }
            }
        }

        cout << "Dijkstra from node " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "To " << i << " : " << dist[i] << "\n";
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    while (true) {
        cout << "\nMenu:\n1. Add Edge\n2. Prim's Algorithm\n3. Kruskal's Algorithm\n4. Dijkstra's Algorithm\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter edge (u v w): ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            }
            case 2:
                g.prim();
                break;
            case 3:
                g.kruskal();
                break;
            case 4: {
                int src;
                cout << "Enter source: ";
                cin >> src;
                g.dijkstra(src);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}