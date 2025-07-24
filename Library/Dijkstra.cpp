//
// Created by STW on 14-Dec-24.
//




/// DIJKSTRA



// const int INF = 1e9;
// int n;
// vector<int> dis, par;
// vector<vector<pair<int, int>>> adj;
//
// void dijkstra(int src) {
//     dis.assign(n, INF);
//     par.assign(n, -1); // initialize the par array
//     priority_queue<pair<int, int>, vector<pii>, greater<pii>> pq;
//
//     dis[src] = 0;
//     pq.push(make_pair(0, src));
//
//     while (!pq.empty()) {
//         int d = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();
//
//         if (d < dis[u]) continue;
//         for (auto &[v, w] : adj[u]) {
//
//             if (dis[u] + w < dis[v]) {
//                 dis[v] = dis[u] + w;
//                 par[v] = u;
//                 pq.emplace(dis[v], v);
//             }
//         }
//     }
// }


/// GET PATH


// vector<int> get_path(int src, int u) {
//     vector<int> path;
//     while (u != src) {
//         path.push_back(u);
//         u = par[u];
//     }
//     path.push_back(u);
//     reverse(path.begin(), path.end());
//     return path;
// }