//
// Created by STW on 10-Apr-25.
//
// #include <bits/stdc++.h>
// using namespace std;
//
//
// int mod = 1000000007;
// void solve() {
//     int n, k; cin >> n >> k;
//     vector<int> a(n);
//     vector dp(n + 1, vector(k + 1, -1));
//     vector dp2(n + 1, vector(k + 1, -1));
//     for (int i = 0; i < n; i++) cin >> a[i];
//
//     function<int(int,int)> calc;
//     function<int(int, int)> rec = [&](int ind, int rem) -> int {
//         if(ind == n) return rem == 0;
//         auto &ret = dp[ind][rem];
//         if(ret != -1) return ret;
//
//         ret = 0;
//         const int lim = min(a[ind], rem);
//         ret = calc(ind + 1, rem) - calc(ind + 1, rem - lim - 1);
//         ret %= mod;
//         if(ret < 0) ret += mod;
//         return ret;
//     };
//     calc= [&](int ind, int rem) -> int {
//         if (rem < 0) return 0;
//         auto &ret = dp2[ind][rem];
//         if(ret != -1) return ret;
//
//         return ret = (rec(ind, rem) + calc(ind, rem - 1)) % mod;
//     };
//
//     cout << rec(0, k);
// }