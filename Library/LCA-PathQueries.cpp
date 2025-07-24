//
// Created by STW on 11-Jul-25.
//
//
//
// using namespace std;
// using namespace __gnu_pbds;
//
//
// const int MAX_N = 1e5 + 10;
// const int LG = 20;
//
// class LCA {
//     int n;
//     vector<int> depth, up[LG];
//
// public:
//     vector<vector<int>> mn, mx;
//
//     explicit LCA(vector<vector<pii>> &adj, int root = 1) {
//         mn = vector (LG, vector<int>(MAX_N, INT_MAX));
//         mx = vector (LG, vector<int>(MAX_N, 0));
//
//
//         n = adj.size();
//         depth.assign(n, 0);
//         for(auto &i: up) i.resize(n);
//
//         up[0][root] = root;
//         dfs(root, 0, adj);
//         init();
//
//     }
//
//     void dfs(int u, int level, vector<vector<pii>> &adj) {
//         for (auto &[v, w] : adj[u]) {
//             if (v == up[0][u]) continue;
//
//             depth[v] = depth[u] + 1;
//             up[0][v] = u;
//             mn[0][v] = w;
//             mx[0][v] = w;
//
//             for (int j = 1; j < LG; j++) {
//                 up[j][v] = up[j - 1][up[j - 1][v]];
//                 mn[j][v] = min(mn[j - 1][v], mn[j - 1][up[j - 1][v]]);
//                 mx[j][v] = max(mx[j - 1][v], mx[j - 1][up[j - 1][v]]);
//             }
//
//             dfs(v, level + 1, adj);
//         }
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
//     int kthAncestor(int node, int k) {
//         for(int bit = 0;bit < LG; bit++) {
//             if(k & (1 << bit)) {
//                 node = up[bit][node];
//             }
//         }
//         return node;
//     }
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
//
//     pair<int, int> getMinMaxToAncestor(int u, int ancestorDepth) {
//         int minW = INT_MAX, maxW = 0;
//         int diff = depth[u] - ancestorDepth;
//         for (int i = 0; i < LG; i++) {
//             if (diff & (1 << i)) {
//                 minW = min(minW, mn[i][u]);
//                 maxW = max(maxW, mx[i][u]);
//                 u = up[i][u];
//             }
//         }
//         return {minW, maxW};
//     }
//
//     pair<int, int> getPathMinMax(int u, int v) {
//         int anc = lca(u, v);
//         auto [min1, max1] = getMinMaxToAncestor(u, depth[anc]);
//         auto [min2, max2] = getMinMaxToAncestor(v, depth[anc]);
//         return {min(min1, min2), max(max1, max2)};
//     }
// };
