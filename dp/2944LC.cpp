#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = prices[0];
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + prices[i-1];
            for(int j = i-1; 2*j >= i; --j) {
                dp[i] = min(dp[i], dp[j-1] + prices[j-1]);
            }
        }
        return dp[n];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
       
    }
    return 0;
}