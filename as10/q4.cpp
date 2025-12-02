// kruskal.cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    for (int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edges.emplace_back(w,u,v);
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total = 0;
    vector<tuple<int,int,int>> chosen;
    for (auto &e: edges){
        int w,u,v; tie(w,u,v)=e;
        if (dsu.unite(u,v)){
            chosen.emplace_back(u,v,w);
            total += w;
        }
    }
    // print MST edges and weight
    for (auto &t: chosen){
        int u,v,w; tie(u,v,w)=t;
        cout << u << " " << v << " " << w << '\n';
    }
    cout << "Total weight: " << total << '\n';
    return 0;
}
