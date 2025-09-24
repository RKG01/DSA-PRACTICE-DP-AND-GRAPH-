class Solution {

    unordered_map<int, bool> dp;

    bool solve(int i, int bucket, int reqsum, int sum, vector<int>& num,
               int mask, int k) {

        if (bucket == k) return true;

        if (sum == reqsum) {
            return solve(0, bucket + 1, reqsum, 0, num, mask, k);
        }

        if (dp.find(mask) != dp.end()) return dp[mask];

        int n = num.size();
        for (int j = i; j < n; j++) {
            if ((mask & (1 << j)) == 0 && sum + num[j] <= reqsum) {
                mask |= (1 << j);

                if (solve(j + 1, bucket, reqsum, sum + num[j], num, mask, k))
                    return dp[mask] = true;

                mask ^= (1 << j);
            }
        }

        return dp[mask] = false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        int reqsum = sum / k;
        sort(nums.rbegin(), nums.rend()); 
        if (nums[0] > reqsum) return false;

        return solve(0, 0, reqsum, 0, nums, 0, k);
    }
};