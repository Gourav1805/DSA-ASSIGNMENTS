// graph_basic.cpp
#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n;
    bool directed;
    vector<vector<int>> adj;        // adjacency list
    vector<vector<int>> adjMat;     // adjacency matrix

    Graph(int n, bool directed=false): n(n), directed(directed) {
        adj.assign(n, {});
        adjMat.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adjMat[u][v] = 1;
        if (!directed) {
            adj[v].push_back(u);
            adjMat[v][u] = 1;
        }
    }

    int degree(int v) { // for undirected: degree, for directed: out-degree
        return (int)adj[v].size();
    }

    int indegree(int v) { // only meaningful if directed
        int d = 0;
        for (int i = 0; i < n; ++i) d += adjMat[i][v];
        return d;
    }

    vector<int> adjacentVertices(int v) {
        return adj[v];
    }

    int numberOfEdges() {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cnt += adjMat[i][j];
        if (!directed) cnt /= 2;
        return cnt;
    }

    void printAdjList() {
        for (int i = 0; i < n; ++i) {
            cout << i << ":";
            for (int v : adj[i]) cout << " " << v;
            cout << '\n';
        }
    }

    void printAdjMat() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << adjMat[i][j] << " ";
            cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Gourav's Graph Basic Program\n";

    int n; bool directed;
    cin >> n >> directed; // first line: n directed(0/1)
    Graph g(n, directed);

    int m; cin >> m; // number of edges
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }

    // sample outputs
    g.printAdjList();
    cout << "Adjacency Matrix:\n";
    g.printAdjMat();

    int q; cin >> q; // queries
    while (q--) {
        int type, v; cin >> type >> v;
        // type: 1 -> degree/out-degree, 2 -> indegree, 3 -> adjacent list, 4 -> edge count
        if (type == 1) cout << g.degree(v) << '\n';
        else if (type == 2) cout << g.indegree(v) << '\n';
        else if (type == 3) {
            auto a = g.adjacentVertices(v);
            for (int x : a) cout << x << " ";
            cout << '\n';
        } else if (type == 4) cout << g.numberOfEdges() << '\n';
    }
    return 0;
}
