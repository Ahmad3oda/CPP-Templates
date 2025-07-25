#include <bits/stdc++.h>
using namespace std;

// Bellman Ford

const int INF = 1e9;
int n;
vector<int> dis(n, INF);
vector<vector<pair<int, int>>> adj;

bool bellman_ford(int src) {
    dis.assign(n + 1, INF);
    dis[src] = 0;

    for (int i = 1; i < n; i++)
        for (int u = 1; u <= n; u++)
            for (auto &[v, w] : adj[u])
                if (dis[u] + w < dis[v])
                    dis[v] = dis[u] + w;

    for (int u = 1; u <= n; u++)
        for (auto &[v, w] : adj[u])
            if (dis[u] + w < dis[v])
                return true; // negative cycle

    return false;
}
