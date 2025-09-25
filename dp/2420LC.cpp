#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> memoInc, memoDec;

    // Longest non-increasing subarray ending at i
    int getNonInc(int i) {
        if (i == 0) return 1;
        if (memoInc[i] != -1) return memoInc[i];
        if (nums[i] <= nums[i - 1])
            return memoInc[i] = 1 + getNonInc(i - 1);
        return memoInc[i] = 1;
    }

    // Longest non-decreasing subarray starting at i
    int getNonDec(int i) {
        if (i == n - 1) return 1;
        if (memoDec[i] != -1) return memoDec[i];
        if (nums[i] <= nums[i + 1])
            return memoDec[i] = 1 + getNonDec(i + 1);
        return memoDec[i] = 1;
    }

    vector<int> goodIndices(vector<int>& arr, int k) {
        nums = arr;
        n = nums.size();
        memoInc.assign(n, -1);
        memoDec.assign(n, -1);

        vector<int> ans;
        for (int i = k; i < n - k; i++) {
            if (getNonInc(i - 1) >= k && getNonDec(i + 1) >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
