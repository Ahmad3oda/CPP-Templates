#include <bits/stdc++.h>
using namespace std;


const int LG = 20;

template<typename T>
class SparseTable {
    vector<vector<T>> st;
public:
    SparseTable(const vector<T> &v) {
        int n = v.size(), lg = 32 - __builtin_clz(n);
        st.assign(lg, v);
        for (int i = 1; i < lg; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

class LCA {
    vector<int> tin, depth, euler;
    SparseTable<pair<int, int>> *st;
public:
    LCA(const vector<vector<int>> &adj, int root = 0) {
        int n = adj.size();
        tin.resize(n), depth.resize(n);
        euler.reserve(2 * n);
        dfs(root, -1, adj);
        vector<pair<int, int>> rmq;
        for (int u : euler) rmq.emplace_back(depth[u], u);
        st = new SparseTable<pair<int, int>>(rmq);
    }
    void dfs(int u, int p, const vector<vector<int>> &adj) {
        tin[u] = euler.size();
        euler.push_back(u);
        for (int v : adj[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
            euler.push_back(u);
        }
    }
    int lca(int u, int v) {
        if (tin[u] > tin[v]) swap(u, v);
        return st->query(tin[u], tin[v]).second;
    }
    int dis(int u, int v) {
        int a = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[a];
    }
};

