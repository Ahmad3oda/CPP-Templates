//
// Created by STW on 23-Jun-25.
//


//
// vector<int> computePrefix(string pat) {
//     int m = pat.size();
//     vector<int> longestPrefix(m);
//     for (int i = 1, k = 0; i < m; i++) {
//         while (k > 0 && pat[k] != pat[i]) {
//             k = longestPrefix[k - 1];
//         }
//         if (pat[i] == pat[k]) {
//             longestPrefix[i] = ++k;
//         } else {
//             longestPrefix[i] = k;
//         }
//     }
//     return longestPrefix;
// }
//
// bool kmp(string str, string pat) {
//     int n = str.size(), m = pat.size();
//     vector<int> longestPrefix = computePrefix(pat);
//     for (int i = 1, k = 0; i < n - 1; i++) {
//         while (k > 0 && pat[k] != str[i]) {
//             k = longestPrefix[k - 1];
//         }
//         if (str[i] == pat[k]) {
//             k++;
//         }
//         if (k == m) {
//             return true;
//         }
//     }
//     return false;
// }
//
// void solve() {
//     string s; cin >> s;
//     int n = s.size();
//
//     vector<int> pi = computePrefix(s);
//     vector<int> ans(n + 1, 1);
//
//
//     for (int i = 0; i < n; i++) {
//         ans[pi[i]] ++;
//     }
//     for(int i = n - 1; i > 0; i--) {
//         ans[pi[i - 1]] += ans[i] - 1;
//     }
//
// }
//
