
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, n));

        for (int len = 2; len <= n; len++) {
            for (int d = 1; d < len; d++) {
                if (len % d != 0) continue;

                for (int i = 0; i + len <= n; i++) {
                    int j = i + len - 1;
                    int cnt = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;

                        while (l < r) {
                            if (s[l] != s[r]) cnt++;

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], cnt);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));

        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                for (int l = i + 1; l < n; l++) {
                    if (dp[l + 1][j - 1] == 1e9) continue;

                    dp[i][j] = min(dp[i][j],
                                   cost[i][l] + dp[l + 1][j - 1]);
                }
            }
        }

        return dp[0][k];
    }
};
