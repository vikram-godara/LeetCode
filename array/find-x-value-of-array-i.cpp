class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);

        vector<long long> dp(k, 0);

        for (int x : nums) {

            vector<long long> ndp(k, 0);

            // Start a new subarray [x]
            ndp[x % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {

                int newRemainder = (r * (x % k)) % k;

                ndp[newRemainder] += dp[r];
            }

            // Add current subarrays to final answer
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};