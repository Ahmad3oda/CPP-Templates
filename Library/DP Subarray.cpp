//
// Created by STW on 10-Apr-25.
//
// #include <bits/stdc++.h>
// using namespace std;
//
// void solve() {
//     int n; cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     vector dp(n + 1, vector(3, -1));
//
//     function<int(int, int)> go = [&](int i, int state)-> int {
//         if(i == n) return 0;
//         auto &ret = dp[i][state];
//         if(~ret) return ret;
//
//         ret = 0;
//         if(state != 2) ret = max(ret, go(i, state + 1));
//         if(state == 1) {
//             ret = max(ret, a[i] + go(i + 1, state));
//         }
//         else {
//             ret = max(ret, go(i + 1, state));
//         }
//         return ret;
//     };
//     cout << go(0, 0);
// }