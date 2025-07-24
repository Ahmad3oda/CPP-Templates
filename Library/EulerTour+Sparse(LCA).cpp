// //
// // Created by STW on 15-Jul-25.
// //
//
// #include <bits/stdc++.h>
// using namespace std;
//
// const int LG = 20;
//
// template<typename T>
// class SparseTable {
//     int n, logn;
//     vector<vector<T>> st;
//
// public:
//     SparseTable(const vector<T> &v) {
//         n = v.size();
//         logn = 32 - __builtin_clz(n);
//         st.resize(logn);
//         st[0] = v;
//
//         for (int i = 1; i < logn; i++) {
//             st[i].resize(n - (1 << i) + 1);
//             for (int j = 0; j + (1 << i) <= n; j++) {
//                 st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
//             }
//         }
//     }
//
//     T query(int l, int r) {
//         int k = 31 - __builtin_clz(r - l + 1);
//         return min(st[k][l], st[k][r - (1 << k) + 1]);
//     }
// };
//
// class LCA {
//     int n, timer;
//
// public:
//     vector<int> depth, tin, tout, euler;
//     SparseTable<pair<int, int>> *st;
//
//     explicit LCA(vector<vector<int>> &adj, int root = 0) {
//         n = adj.size();
//         depth.assign(n, 0);
//         tin.assign(n, 0);
//         tout.assign(n, 0);
//         euler.reserve(2 * n);
//
//         timer = 0;
//         dfs(root, -1, adj);
//
//         vector<pair<int, int>> rmqArr;
//         for (int i = 0; i < euler.size(); i++) {
//             rmqArr.emplace_back(depth[euler[i]], euler[i]);
//         }
//
//         st = new SparseTable<pair<int, int>>(rmqArr);
//     }
//
//     void dfs(int u, int p, vector<vector<int>> &adj) {
//         tin[u] = euler.size();
//         euler.push_back(u);
//
//         for (int v : adj[u]) {
//             if (v == p) continue;
//             depth[v] = depth[u] + 1;
//             dfs(v, u, adj);
//             euler.push_back(u);
//         }
//
//         tout[u] = euler.size() - 1;
//     }
//
//     int lca(int u, int v) {
//         if (tin[u] > tin[v]) swap(u, v);
//         return st->query(tin[u], tin[v]).second;
//     }
//
//     int dis(int u, int v) {
//         int node = lca(u, v);
//         return depth[u] + depth[v] - 2 * depth[node];
//     }
// };
