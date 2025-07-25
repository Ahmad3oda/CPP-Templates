
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
 
class EulerTourTree {
    int n, timer;
    vector<int> in, out, flatTree, nodeValue;
    SegTree<int> seg;
 
public:
    EulerTourTree(int _n, vector<vector<int>> &adj, vector<int> &initialValues)
        : n(_n),
          timer(0),
          in(_n + 1),
          out(_n + 1),
          flatTree(_n),
          nodeValue(initialValues),
          seg(buildSegmentTree(_n, adj))
    {}
 
private:
    SegTree<int> buildSegmentTree(int _n, vector<vector<int>> &adj) {
        dfs(1, 0, adj);
        vector<int> tourArray(n);
        for (int i = 0; i < n; ++i)
            tourArray[i] = nodeValue[flatTree[i]];
        return SegTree<int>(tourArray);
    }
 
    void dfs(int u, int p, const vector<vector<int>> &adj) {
        in[u] = timer;
        flatTree[timer++] = u;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, adj);
        }
        out[u] = timer - 1;
    }
 
public:
    int querySubtree(int u) {
        return seg.get(in[u], out[u]);
    }
 
    void updateNode(int u, int val) {
        seg.set(in[u], val);
    }
};
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++) cin >> values[i];
 
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    EulerTourTree ett(n, adj, values);
 
    while (m--) {
        int op; cin >> op;
        if(op == 2) {
            int x; cin >> x;
            cout << ett.querySubtree(x) << endl;
        }
        else {
            int x, v; cin >> x >> v;
            ett.updateNode(x, v);
        }
    }
}
