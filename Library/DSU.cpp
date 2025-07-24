//
// Created by STW on 03-Dec-24.
//

// #include <bits/stdc++.h>
// using namespace std;
//
// int N = 1e5 + 5;
// vector <int> par(N);
//
// int fnd(int u) {
//     if(par[u] == u) return u;
//     return par[u] = fnd(par[u]);
// }
// bool uni(int s, int t) {
//     t = fnd(t), s = fnd(s);
//
//     if(s == t) return false;
//     return par[s] = t, true;
// }
//
// /// Applying Kruskal using DSU
// void connect() {
//     vector<array <int, 3>> edges(N);
//
//     int val = 0;
//     sort(edges.begin(), edges.end());
//
//     for(auto &[w, u, v]: edges) {
//         if(uni(w, u)) val += w;
//     }
//
//     cout << val;
// }
// // DSU Class
// class DSU {
// public:
//     vector <int> par;
//     int __comps;
//     DSU(int __N) {
//         par.resize(__N + 1);
//         iota(par.begin(), par.end(), 0);
//         __comps = __N;
//     }
//
//     int fnd(int u) {
//         if(par[u] == u) return u;
//         return par[u] = fnd(par[u]);
//     }
//
//     bool uni(int s, int t) {
//         t = fnd(t), s = fnd(s);
//
//         if(s == t) return false;
//         return par[s] = t, __comps --, true;
//     }
//
//     int components() const { return __comps; }
// };