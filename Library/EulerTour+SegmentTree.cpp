// //
// // Created by STW on 15-Jul-25.
// //
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
//
// using namespace std;
//
// class EulerTourTree {
//     int n, timer;
//     vector<int> in, out, flatTree, nodeValue;
//     SegTree<int> seg;
//
// public:
//
//     explicit EulerTourTree(int _n, vector<vector<int>> &adj, vector<int> &initialValues)
//         : n(_n), timer(0), in(n + 1), out(n + 1), flatTree(n), nodeValue(initialValues) {
//
//         dfs(1, 0, adj);
//
//         vector<int> tourArray(n);
//         for (int i = 0; i < n; ++i)
//             tourArray[i] = nodeValue[flatTree[i]];
//
//         seg = SegTree<int>(tourArray);
//     }
//     void dfs(int u, int p, vector<vector<int>> &adj) {
//         in[u] = timer;
//         flatTree[timer] = u;
//         timer++;
//
//         for (int v : adj[u]) {
//             if (v == p) continue;
//             dfs(v, u, adj);
//         }
//
//         out[u] = timer - 1;
//     }
//     int querySubtree(int u) {
//         return seg.get(in[u], out[u]);
//     }
//     void updateNode(int u, int val) {
//         seg.set(in[u], val);
//     }
// };
//
// void solve() {
//     int n;
//     cin >> n;
//     vector<int> values(n + 1);
//     for (int i = 1; i <= n; i++) cin >> values[i];
//
//     vector<vector<int>> adj;
//     for (int i = 0; i < n - 1; ++i) {
//         int u, v; cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//
//     EulerTourTree ett(n, adj, values);
//
//     int x; cin >> x;
//     cout << ett.querySubtree(x) << "\n";
//
//     int val; cin >> x >> val;
//     ett.updateNode(x, val);
// }
