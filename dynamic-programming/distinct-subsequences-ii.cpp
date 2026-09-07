class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        // dp = number of distinct subsequences including empty
        long long dp = 1;

        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (char ch : s) {
            int c = ch - 'a';

            long long newDp = (2 * dp - last[c] + MOD) % MOD;

            // For the next occurrence of this character,
            // remove the subsequences that existed before this occurrence.
            last[c] = dp;

            dp = newDp;
        }

        // Remove the empty subsequence.
        return (dp - 1 + MOD) % MOD;
    }
};
