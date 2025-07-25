#include <bits/stdc++.h>
using namespace std;

// FLOYD.
vector<vector<int>> floyd(){
    int n, e; cin >> n >> e;
    vector<vector<int>> adj(n, vector<int>(e, 2e9));

    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    for(int m = 1; m <= n; m ++) {
        for(int u = 1; u <= n; u ++) {
            for(int v = 1; v <= n; v ++) {
                adj[u][v] = min(adj[u][v], adj[u][m] + adj[m][v]);
            }
        }
    }

    return adj;
}
