
class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        int mn = INT_MAX;

        for (auto &it : items) {
            freq[it[0]]++;
            mn = min(mn, it[1]);
        }

        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<pair<int, int>> v;

        for (auto &it : items) {
            int f = it[0];
            int p = it[1];

            if (cnt[f] > 1 && p < 2LL * mn) {
                v.push_back({p, cnt[f] - 1});
            }
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        long long rem = budget;

        for (auto &[price, freeCnt] : v) {
            long long take = min((long long)freeCnt, rem / price);

            ans += 2 * take;
            rem -= take * price;
        }

        ans += rem / mn;

        return ans;
    }
};
