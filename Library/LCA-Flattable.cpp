// //
// // Created by STW on 15-Jul-25.
// //
//
// #include <bits/stdc++.h>
// using namespace std;
//
//
// const int LG = 20;
// class LCA {
//     int n, timer;
//
// public:
//     vector<int> depth, parent, up[LG], tin, tout;
//     vector<vector<int>> depthNodes;
//     explicit LCA(vector<vector<int>> &adj, int root = 0) {
//         n = adj.size();
//         depth.assign(n, 0);
//         parent.assign(n, 0);
//         tin.assign(n, 0);
//         tout.assign(n, 0);
//         depthNodes.resize(n);
//         for(auto &i: up) i.resize(n);
//         timer = 0;
//         up[0][root] = -1;
//         dfs(root, 0, adj);
//         init();
//     }
//
//     void dfs(int u, int level, vector<vector<int>> &adj) {
//         tin[u] = timer++;
//         depthNodes[level].emplace_back(tin[u]);
//
//         for(auto &v: adj[u]) {
//             if(up[0][u] == v) continue;
//             parent[v] = u;
//             depth[v] = depth[u] + 1;
//             up[0][v] = u;
//             dfs(v, level + 1, adj);
//         }
//         tout[u] = timer++;
//     }
//
//     void init() {
//         for (int i = 1; i < LG; i++) {
//             for (int node = 0; node < n; node++) {
//                 if (up[i - 1][node] == -1) {
//                     up[i][node] = -1;  // No higher ancestor
//                 } else {
//                     up[i][node] = up[i - 1][up[i - 1][node]];
//                 }
//             }
//         }
//     }
//
//
//     int kthAncestor(int node, int k) {
//         for (int bit = 0; bit < LG; bit++) {
//             if (k & (1 << bit)) {
//                 if (node == -1) return 0;
//                 node = up[bit][node];
//             }
//         }
//         return node;
//     }
//
//
//     int lca(int u, int v) {
//         if(depth[u] > depth[v]) swap(u, v);
//
//         int diff = depth[v] - depth[u];
//         v = kthAncestor(v, diff);
//
//         if(u == v) return u;
//
//         for(int i = LG - 1; i >= 0; i--) {
//             if(up[i][v] != up[i][u]) {
//                 v = up[i][v];
//                 u = up[i][u];
//             }
//         }
//         return up[0][u];
//     }
//
//     int dis(int u, int v) {
//         int node = lca(u, v);
//         return depth[u] + depth[v] - 2 * depth[node];
//     }
// };