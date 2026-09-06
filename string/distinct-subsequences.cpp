class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<unsigned long long> dp(n + 1, 0);

        // Empty t can be formed in exactly one way.
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            // Go backward to avoid overwriting dp[j - 1].
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};
