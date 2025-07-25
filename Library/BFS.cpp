#include <bits/stdc++.h>
using namespace std;

void bfs(int src, const vector<vector<int>> &adj, vector<int> &dis) {
    int n = adj.size();
    dis.assign(n, -1);
    queue<int> q;
    q.push(src), dis[src] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dis[v] == -1)
            dis[v] = dis[u] + 1, q.push(v);
    }
}

void bfs01(int src, const vector<vector<pair<int, int>>> &adj, vector<int> &dis) {
    int n = adj.size();
    dis.assign(n, 1e9);
    deque<int> dq;
    dq.push_front(src), dis[src] = 0;

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                w ? dq.push_back(v) : dq.push_front(v);
            }
        }
    }
}

bool topo_bfs(const vector<vector<int>> &adj, vector<int> &order) {
    int n = adj.size();
    vector<int> in(n);
    for (auto &v : adj)
        for (int u : v) in[u]++;

    queue<int> q;
    for (int i = 0; i < n; i++) if (!in[i]) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--in[v] == 0)
            q.push(v);
    }

    return order.size() == n; // true if DAG, false if cycle exists
}
