class Solution {
    int solve(int i, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (r == 0 ? 0 : INT_MIN); 
        }
        if (dp[i][r] != -1) return dp[i][r];

        int take = nums[i] + solve(i + 1, (r + nums[i]) % 3, nums, dp);

        int skip = solve(i + 1, r, nums, dp);

        return dp[i][r] = max(take, skip);
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, 0, nums, dp);
    }
};
©leetcode