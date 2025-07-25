
const int MAXN = 1e6 + 10;
vector<int> pi;
vector<vector<int>> dp;

// Builds the prefix function for string `s`
void computePrefix(const string &s) {
    int n = s.size();
    pi.assign(n + 20, 0); // ensure enough room for t extensions

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
}

// Builds the automaton transitions from `pi`
void buildAutomaton(const string &s) {
    int n = s.size();
    dp.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (s[i] - 'a' == c)
                dp[i][c] = i + 1;
            else if (i == 0)
                dp[i][c] = 0;
            else
                dp[i][c] = dp[pi[i - 1]][c];
        }
    }
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    computePrefix(s);
    buildAutomaton(s);

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        int k = pi[n - 1]; // start from last prefix state of s
        for (int i = 0; i < (int)t.size(); i++) {
            // Extend the prefix function while matching s + t
            while (k > 0 && t[i] != (k >= n ? t[k - n] : s[k])) {
                k = (k < n ? dp[pi[k - 1]][t[i] - 'a'] : pi[k - 1]);
            }
            if (t[i] == (k >= n ? t[k - n] : s[k])) {
                ++k;
            }
            pi[n + i] = k;
            cout << k << " ";
        }
        cout << '\n';
    }
}
