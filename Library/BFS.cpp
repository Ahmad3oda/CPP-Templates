// //
// // Created by STW on 21-Nov-24.
// //
//
// #include <bits/stdc++.h>
// using namespace std;
//
// vector < vector < int > > graph;
// void bfs(int src){
//     int n = graph.size();
//
//     vector < bool > vis(n);
//     queue < int > q;
//
//     vis[src] = true;
//     q.push(src);
//
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         cout << u << ' ';
//         for(int v : graph[u]){
//             if(!vis[v]){
//                 vis[v] = true;
//                 q.push(v);
//             }
//         }
//     }
// }