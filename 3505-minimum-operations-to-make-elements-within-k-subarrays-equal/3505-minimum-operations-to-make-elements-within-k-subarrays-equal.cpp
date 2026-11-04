class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = 1e18;

        vector<long long> cost(n - x + 1);

        multiset<int> low, high;
        long long sum1 = 0, sum2 = 0;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sum1 -= val;
                high.insert(val);
                sum2 += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                sum2 -= val;
                low.insert(val);
                sum1 += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sum1 += val;
            } else {
                high.insert(val);
                sum2 += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sum1 -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sum2 -= val;
            }
            balance();
        };

        auto getCost = [&]() -> long long {
            long long mid = *low.rbegin();

            return mid * low.size() - sum1
                 + sum2 - mid * high.size();
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                                  prev[i - x] + cost[i - x]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};