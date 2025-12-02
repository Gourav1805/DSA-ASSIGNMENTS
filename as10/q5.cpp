// prim.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0}); // weight, node (start at 0)
    long long total = 0;
    vector<pair<int,int>> tree; // (parent, node) not storing parent weight for simplicity
    vector<int> parent(n, -1);
    while(!pq.empty()){
        auto [w,u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        total += w;
        if (parent[u] != -1) tree.push_back({parent[u], u});
        for (auto &e : adj[u]){
            int v = e.first, wt = e.second;
            if (!vis[v]){
                pq.push({wt, v});
                if (parent[v]==-1 || wt < 0) parent[v] = u; // parent set but not strict minimum; we will adjust below
            }
        }
    }
    // Better: run prim tracking parent & minWeight
    // Re-run clean prim to set parents correctly:
    fill(vis.begin(), vis.end(), 0);
    parent.assign(n, -1);
    vector<int> minW(n, INT_MAX);
    minW[0] = 0;
    pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    pq.push({0,0});
    total = 0;
    while(!pq.empty()){
        auto [w,u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        total += w;
        for (auto &e: adj[u]){
            int v = e.first, wt = e.second;
            if (!vis[v] && wt < minW[v]){
                minW[v] = wt;
                parent[v] = u;
                pq.push({minW[v], v});
            }
        }
    }
    for (int i = 1; i < n; ++i) if (parent[i] != -1) cout << parent[i] << " " << i << " " << minW[i] << '\n';
    cout << "Total weight: " << total << '\n';
    return 0;
}
