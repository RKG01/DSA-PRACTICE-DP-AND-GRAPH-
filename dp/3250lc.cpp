#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    /*
    Approach:
    - We want to count all valid pairs of splits for each number in the array.
    - Let f(i, prev) represent the number of valid ways starting from index i,
      given that the previous value in the first part is 'prev'.
    - For each nums[i], we try all possible splits 'val' for the first part such that:
        1. val >= prev (non-decreasing constraint)
        2. nums[i] - val <= previous second part (non-increasing constraint)
    - Use memoization (dp[i][prev]) to avoid recomputation.
    - Base case: i == n, return 1 (one valid way).
    - Time complexity: O(n * max(nums[i])) due to memoization.
    */

private:
    int dfs(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
            return 1;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        int count = 0;

        for (int val = prev; val <= nums[i]; val++)
        {
            int secondPart = nums[i] - val;

            if (i == 0 || secondPart <= nums[i - 1] - prev)
            {
                count = (count + dfs(i + 1, val, nums, dp)) % MOD;
            }
        }

        return dp[i][prev] = count;
    }

    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(maxVal + 2, -1));
        return dfs(0, 0, nums, dp);
    }

private:
    int dfs(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
            return 1;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        int count = 0;

        for (int val = prev; val <= nums[i]; val++)
        {
            int secondPart = nums[i] - val;

            if (i == 0 || secondPart <= nums[i - 1] - prev)
            {
                count = (count + dfs(i + 1, val, nums, dp)) % MOD;
            }
        }

        return dp[i][prev] = count;
    }
};
