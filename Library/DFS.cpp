#include <bits/stdc++.h>
using namespace std;

/// Cycle Detection - Returns true if cycle starts from node u.
vector<vector<int>> graph;
vector<int> vis;
bool dfs(int u) {
    vis[u] = 1;
    bool cyclic = false;
    for (auto i: graph[u]) {
        if (!vis[i])
            cyclic |= dfs(i);
        else if (vis[i] == 1)
            return true;
    }
    vis[u] = 2;
    return cyclic;
}


/// Bipartite Graph Check - Returns true if graph can be Bipartite
vector<vector<int>> graph;
vector<int> color;
bool dfs(int u) {
    bool isBipartite = true;
    for (int i: graph[u]) {
        if (!color[i]) {
            color[i] = color[u] == 1 ? 2 : 1;
            isBipartite &= dfs(i);
        }
        else if (color[i] == color[u])
            return false;
    }
    return isBipartite;
}


/// Topological Order - Returns true if cycle detected + topo vector is adjusted
vector<vector<int>> graph;
vector<int> vis;
bool dfs(int u, vector<int> &topo_order) {
    vis[u] = 1;
    bool cyclic = false;
    for (int i: graph[u]) {
        if (vis[i] == 1)
            return true; // Cycle detected
        if (!vis[i])
            cyclic |= dfs(i, topo_order);
    }
    vis[u] = 2;
    topo_order.push_back(u);
    return cyclic;
}
