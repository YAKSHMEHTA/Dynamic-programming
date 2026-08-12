#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for(auto it:adj[node]){
                int next = it.first;
                int wt = it.second;

                int cost = dis + wt;

                if(cost < dist[next]){
                    dist[next] = cost;
                    pq.push({cost,next});
                }
            }
        }

        for(int i=0;i<V;i++){
            cout<<dist[i]<<" ";
        }
    }

};

int main() {

    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 3);

    g.dijkstra(0);

    return 0;
}