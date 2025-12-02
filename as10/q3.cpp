// dfs.cpp
#include <bits/stdc++.h>
using namespace std;

void dfsRec(int u, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : adj[u]) if (!vis[v]) dfsRec(v, adj, vis, order);
}

vector<int> dfsRecursive(const vector<vector<int>>& adj, int src) {
    vector<int> vis(adj.size(), 0), order;
    dfsRec(src, adj, vis, order);
    return order;
}

vector<int> dfsIterative(const vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> vis(n, 0), order;
    stack<int> st; st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        order.push_back(u);
        // push neighbors in reverse for similar order to recursive
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) if (!vis[*it]) st.push(*it);
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
    auto r = dfsRecursive(adj, src);
    for (int x : r) cout << x << " ";
    cout << '\n';
    auto it = dfsIterative(adj, src);
    for (int x : it) cout << x << " ";
    cout << '\n';
    return 0;
}
