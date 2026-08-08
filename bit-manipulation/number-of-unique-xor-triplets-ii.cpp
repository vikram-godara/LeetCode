class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> suffixPair(MAXX, false);
        vector<bool> ans(MAXX, false);

        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            vector<bool> cur = suffixPair;

            // Pair (i, i)
            cur[0] = true;

            // Pairs (i, k), k > i
            for (int k = i + 1; k < n; k++) {
                cur[nums[i] ^ nums[k]] = true;
            }

            // Triplets starting with i
            for (int x = 0; x < MAXX; x++) {
                if (cur[x])
                    ans[x ^ nums[i]] = true;
            }

            suffixPair = cur;
        }

        int cnt = 0;
        for (bool v : ans)
            if (v) cnt++;

        return cnt;
    }
};