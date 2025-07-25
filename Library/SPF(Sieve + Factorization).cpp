#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int spf[N]; // spf[i] = smallest prime factor of i

void sieve() {
    iota(spf, spf + N, 0); // spf[i] = i initially
    for (int i = 2; i * i < N; ++i)
        if (spf[i] == i)
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j) spf[j] = i;
}

vector<int> factorize(int x) {
    vector<int> f;
    while (x > 1) {
        f.push_back(spf[x]);
        x /= spf[x];
    }
    return f;
}

void solve() {
    sieve();
    vector<int> f = factorize(16);
    for(auto i: f) cout << i << " ";
}
