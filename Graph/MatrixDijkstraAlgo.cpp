#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> mat;

public:
    Graph(int V) {
        this->V = V;

        mat.assign(V, vector<int>(V, INT_MAX));

        for (int i = 0; i < V; i++) {
            mat[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int wt) {
        mat[u][v] = wt;
    }

    void dijkstra(int src) {
        // TODO: Implement Dijkstra here
    }
};

int main() {

    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    g.dijkstra(0);

    return 0;
}