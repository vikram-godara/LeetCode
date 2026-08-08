class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> coins;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (dp[i] < numWays[i - 1]) {
                coins.push_back(i);
                for (int j = i; j <= n; ++j) {
                    dp[j] += dp[j - i];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dp[i] != numWays[i - 1])
                return {};
        }
        return coins;
    }
};