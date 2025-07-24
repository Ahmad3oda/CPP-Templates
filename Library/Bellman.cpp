//
// Created by STW on 04-Jan-25.
//





// Bellman Ford

//
//
// #include <bits/stdc++.h>
// using namespace std;
//
//
// const int INF = 1e9;
// int n;
// vector<int> dis(n, INF);
// vector<vector<pair<int, int>>> adj;
//
// bool relax() {
//     bool fnd = false;
//
//     for(int u = 1; u <= n; u++) {
//         for(auto &[v, w]: adj[u]) {
//             if(dis[u] + w < dis[v]) {
//                 fnd = true;
//                 dis[v] = dis[u] + w;
//             }
//         }
//     }
//     return fnd;
// }
//
// bool bellmanFord(int src) {
//     dis[src] = 0;
//
//     for (int i = 0; i < n - 1; i++) {
//         if(!relax()) return false;
//     }
//     return relax();
// }
