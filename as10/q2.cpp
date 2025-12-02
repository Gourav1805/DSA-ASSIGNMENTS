// bfs.cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> vis(n, 0), order;
    queue<int> q;
    vis[src] = 1; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment out if directed
    }
    int src; cin >> src;
    auto order = bfs(adj, src);
    for (int x : order) cout << x << " ";
    cout << '\n';
    return 0;
}
