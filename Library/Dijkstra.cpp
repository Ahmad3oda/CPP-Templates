#include <bits/stdc++.h>
using namespace std;


// DIJKSTRA
#define pii pair <int,int>

const int INF = 1e9;
int n;
vector<int> dis, par;
vector<vector<pair<int, int>>> adj;

void dijkstra(int src) {
    dis.assign(n + 1, INF);
    par.assign(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dis[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;

        for (auto &[v, w] : adj[u])
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                par[v] = u;
                pq.emplace(dis[v], v);
            }
    }
}

vector<int> get_path(int src, int u) {
    if (dis[u] == INF) return {};
    vector<int> path;
    while (u != -1) path.push_back(u), u = par[u];
    reverse(path.begin(), path.end());
    return path;
}
