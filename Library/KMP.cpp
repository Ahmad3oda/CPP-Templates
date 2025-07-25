vector<int> computePrefix(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

bool kmp(const string &text, const string &pattern) {
    vector<int> pi = computePrefix(pattern);
    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == pattern.size()) return true; // match found
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = computePrefix(s);
    vector<int> freq(n + 1); // count of each prefix length

    for (int i = 0; i < n; i++)
        freq[pi[i]]++;

    for (int i = n - 1; i > 0; i--)
        freq[pi[i - 1]] += freq[i];

    for (int i = 0; i <= n; i++)
        freq[i]++; // include the prefix itself
}

