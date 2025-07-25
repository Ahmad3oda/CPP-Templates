#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

const int N = 1e5;
vector<int> freq(N + 1), freqFreq(N + 1);

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<vector<int>> g(n);
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(q);
    vector<vector<pair<int, int>>> queries(n);
    for(int i = 0, u, c; i < q; i++) {
        cin >> u >> c, u--;
        queries[u].emplace_back(c, i);
    }

    vector<int> sz(n, 1);
    function<void(int)> dfs_pre = [&](int u) {
        for(int &v : g[u]) {
            g[v].erase(find(g[v].begin(), g[v].end(), u));
            dfs_pre(v);
            sz[u] += sz[v];
            if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
        }
    };
    dfs_pre(0);

    auto add = [&](int val) {
        freq[val]++;
        freqFreq[freq[val]]++;
    };
    auto pop = [&](int val) {
        freqFreq[freq[val]]--;
        freq[val]--;
    };

    vector<int> sub;
    function<void(int)> collect = [&](int u) {
        sub.push_back(u);
        for(int v : g[u]) {
            collect(v);
        }
    };

    function<void(int, bool)> dfs = [&](int u, bool keep) {
        for(int i = 1; i < g[u].size(); i++) {
            int v = g[u][i];
            dfs(v, false);
        }

        if(!g[u].empty())
            dfs(g[u][0], true);

        add(a[u]);
        for(int i = 1; i < g[u].size(); i++) {
            int v = g[u][i];
            sub.clear();
            collect(v);
            for(int k : sub) {
                add(a[k]);
            }
        }

        for(auto [c, i] : queries[u])
            ans[i] = freqFreq[c];

        if(!keep) {
            sub.clear();
            collect(u);
            for(int v : sub) {
                pop(a[v]);
            }
        }
    };
    dfs(0, true);
    for(int i : ans)
        cout << i << '\n';
}
