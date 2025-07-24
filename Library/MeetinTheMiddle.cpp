//
// Created by STW on 24-Jul-25.
//

#include <bits/stdc++.h>
using namespace std;

class MeetInTheMiddle {
    int n, m;
    vector<int> left, right;

    int subset_sum(int mask, const vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (mask >> i & 1) {
                sum = (sum + arr[i]) % m;
            }
        }
        return sum;
    }

public:
    MeetInTheMiddle(int n, int m, const vector<int> &a) : n(n), m(m) {
        int mid = (n + 1) / 2;
        left = vector<int>(a.begin(), a.begin() + mid);
        right = vector<int>(a.begin() + mid, a.end());
    }

    int query() {
        set<int> left_sums;
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            left_sums.insert(subset_sum(mask, left));
        }

        int ans = *left_sums.rbegin();
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            int sum = subset_sum(mask, right);

            // depends on the problem.
            // -------------------------------------
            auto it = left_sums.lower_bound(m - sum);
            if (it != left_sums.begin()) {
                --it;
                ans = max(ans, (sum + *it) % m);
            } else {
                ans = max(ans, sum);
            }
            // -------------------------------------
        }

        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)  cin >> a[i];

    MeetInTheMiddle mitm(n, m, a);
    cout << mitm.query();

}