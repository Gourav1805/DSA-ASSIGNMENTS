// dijkstra.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        // if undirected add adj[v].push_back({u,w});
    }
    int src; cin >> src;
    vector<ll> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});
    while (!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : adj[u]){
            int v = e.first; ll w = e.second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i=0;i<n;i++){
        if (dist[i] == INF) cout << "INF\n"; else cout << dist[i] << '\n';
    }
    return 0;
}
