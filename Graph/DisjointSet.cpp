#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>

const int N = 2e5 + 5;

vector<int> adj[N];              // Unweighted graph
vector<pii> weightedAdj[N];      // {neighbor, weight}

int n, m;

void dfs(int node, vector<bool> &vis) {
    vis[node] = true;

    for (int child : adj[node]) {
        if (!vis[child])
            dfs(child, vis);
    }
}

void bfs(int src) {
    vector<bool> vis(n + 1, false);
    queue<int> q;

    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);   // Remove for directed graph
    }

    return 0;
}