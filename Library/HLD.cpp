//
// template<typename T = int>
// struct HLD {
//     struct SegmentTree {
//         int n;
//         vector<T> tree;
//
//         SegmentTree(int size) {
//             n = size;
//             tree.assign(2 * n, 0);
//         }
//
//         void build(const vector<T>& a) {
//             for (int i = 0; i < n; i++)
//                 tree[i + n] = a[i];
//             for (int i = n - 1; i > 0; --i)
//                 tree[i] = tree[i << 1] + tree[i << 1 | 1];
//         }
//
//         void update(int pos, T val) {
//             for (tree[pos += n] = val; pos > 1; pos >>= 1)
//                 tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
//         }
//
//         T query(int l, int r) { // inclusive [l, r]
//             T res = 0;
//             for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
//                 if (l & 1) res += tree[l++];
//                 if (!(r & 1)) res += tree[r--];
//             }
//             return res;
//         }
//     };
//
//
//     int n, root = 0, cnt = 0;
//     vector<vector<int>> g;
//     vector<int> sz, in, out, top, par, lvl, seq;
//     vector<T> a;
//     SegmentTree seg;
//
//     HLD(int _n, vector<T>& _a) : n(_n), g(_n), a(_a), seg(_n) {}
//
//     void add(int u, int v) {
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//
//     void init(int rt = 0) {
//         root = rt;
//         sz.assign(n, 1);
//         in.resize(n); out.resize(n); top.resize(n);
//         par.resize(n); lvl.resize(n); seq.resize(n);
//         par[root] = root;
//         top[root] = root;
//         dfs(root);
//         decompose(root);
//         vector<T> flat(n);
//         for (int i = 0; i < n; i++) {
//             flat[in[i]] = a[i];
//         }
//         seg.build(flat);
//     }
//
//     void dfs(int u) {
//         for (int &v : g[u]) {
//             if (v == par[u]) continue;
//             lvl[v] = lvl[u] + 1;
//             par[v] = u;
//             dfs(v);
//             sz[u] += sz[v];
//             if (sz[v] > sz[g[u][0]] || g[u][0] == par[u])
//                 swap(v, g[u][0]);
//         }
//     }
//
//     void decompose(int u) {
//         in[u] = cnt++;
//         seq[in[u]] = u;
//         for (int v : g[u]) {
//             if (v == par[u]) continue;
//             top[v] = (v == g[u][0] ? top[u] : v);
//             decompose(v);
//         }
//         out[u] = cnt - 1;
//     }
//
//     void update(int u, T val) {
//         seg.update(in[u], val);
//     }
//
//     T get(int u, int v) {
//         T res = 0;
//         while (top[u] != top[v]) {
//             if (lvl[top[u]] < lvl[top[v]])
//                 swap(u, v);
//             res += seg.query(in[top[u]], in[u]);
//             u = par[top[u]];
//         }
//         if (lvl[u] > lvl[v])
//             swap(u, v);
//         res += seg.query(in[u], in[v]);
//         return res;
//     }
// };
//
// void solve() {
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (int &x : a) cin >> x;
//
//     HLD hld(n, a);
//
//     for (int i = 1; i < n; i++) {
//         int u, v;
//         cin >> u >> v;
//         u--, v--;
//         hld.add(u, v);
//     }
//
//     hld.init(0);
//
//     while (q--) {
//         int op;
//         int u, v;
//         cin >> op >> u;
//         u--;
//         if (op == 2) {
//             cout << hld.get(0, u) << '\n';
//         } else if (op == 1) {
//             cin >> v;
//             hld.update(u, v);
//         }
//     }
// }
//
