#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const string& s) {
    string t = "@";
    for (char c : s) t += "#" + string(1, c);
    t += "#$";

    int n = t.size();
    vector<int> p(n); // p[i]: radius around center i
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right) p[i] = min(right - i, p[mirror]);

        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    // Optional: extract odd-length palindromes' radius centered at each s[i]
    vector<int> res(s.size());
    for (int i = 0; i < s.size(); i++)
        res[i] = p[2 + 2 * i] / 2;
    return res;
}

void solve() {
    string s = "abacaba";
    vector<int> pal_radius = manacher(s);

    // pal_radius[i] = max length r such that s[i - r .. i + r] is a palindrome
}
