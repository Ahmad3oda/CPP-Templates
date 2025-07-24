// vector<int> zAlgo(string s) {
//     int n = s.size();
//
//     vector<int> z(n);
//     int l = 0, r = 0;
//     for (int i = 1; i < n; i++) {
//         if (i < r) {
//             z[i] = min(r - i, z[i - l]);
//         }
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             z[i]++;
//         }
//         if (i + z[i] > r) {
//             l = i;
//             r = i + z[i];
//         }
//
//     }
//     // for (int x: z) cout << x << " ";
//     // cout << endl;
//     return z;
// }
//
// void solve() {
//     string s; cin >> s;
//     int n = s.size();
//     vector<int> z = zAlgo(s);
//     vector<int> freq(n + 1, 0);
//     for (int i = 1; i < n; i++) {
//         if (z[i] > 0) {
//             freq[z[i]]++;
//         }
//     }
//     for (int i = n - 1; i >= 1; i--) {
//         freq[i] += freq[i + 1];
//     }
//     for (int i = 1; i <= n; i++) {
//         freq[i]++;
//         // cout << freq[i] << " ";
//     }
//
//     vector<pair<int, int>> res;
//     for (int l = 1; l <= n; l++) {
//         if (z[n - l] == l) {
//             res.emplace_back(l, freq[l]);
//         }
//     }
//     res.emplace_back(n, 1);
//     sort(res.begin(), res.end());
//     cout << res.size() << "\n";
//     for (auto &[l, c] : res) {
//         cout << l << " " << c << "\n";
//     }
// }
