// https://codeforces.com/problemset/problem/1673/C

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

const ll MOD = 1e9 + 7;

bool check(int n) {
    string s = to_string(n);
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }

}

int main() {
    fastio();
    int t;
    cin >> t;
    vector<int> queries(t);
    int maxn = 0;
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        maxn = max(maxn, queries[i]);
    }

    vector<int> pals;
    for (int i = 1; i <= maxn; i++) {
        if (check(i)) pals.push_back(i);
    }

    vector<int> dp(maxn + 1, 0);
    dp[0] = 1;
    for (int p : pals) {
        for (int j = p; j <= maxn; j++) {
            dp[j] += dp[j - p];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    for (int n : queries) {
        cout << dp[n] << "\n";
    }
    return 0;
}
