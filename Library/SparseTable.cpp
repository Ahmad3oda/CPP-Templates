// #include <bits/stdc++.h>
//
// using namespace std;
//
// const int LG = 20;
// template<class F>
// class SparseTable{
//
//     int n;
//     F merge;
//     vector<int> table[LG];
//
// public:
//     explicit SparseTable(vector<int> &a , const F& f) : merge(f){
//         n = a.size();
//         for (auto &i : table) i.resize(n);
//
//         for(int i = 0; i < n; i++) {
//             table[0][i] = a[i];
//         }
//         for(int i = 1; i < LG; i++) {
//             for(int j = 0; j + (1 << i) - 1 < n; j++) {
//                 table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
//             }
//         }
//     }
//     int get(int l, int r) {
//         int x = __lg(r - l + 1);
//         int res = merge(table[x][l], table[x][r - (1 << x) + 1]);
//         return res;
//     }
// };