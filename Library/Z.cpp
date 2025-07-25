#include <bits/stdc++.h>
using namespace std;

vector<int> zAlgo(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> z = zAlgo(s);
    vector<int> freq(n + 2, 0); // freq[i] = how many times prefix of length i occurs

    for (int i = 1; i < n; ++i)
        ++freq[z[i]];

    for (int i = n - 1; i >= 1; --i)
        freq[i] += freq[i + 1];

    for (int i = 1; i <= n; ++i)
        ++freq[i]; // include the prefix itself

    vector<pair<int, int>> res;
    for (int l = 1; l <= n; ++l) {
        if (z[n - l] == l)
            res.emplace_back(l, freq[l]);
    }
    res.emplace_back(n, 1); // full string is always a border of itself

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto& [len, count] : res)
        cout << len << ' ' << count << '\n';
}
