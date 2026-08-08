class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> arr(n);
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                arr[i] = 1;
                found = true;
            } else {
                arr[i] = -1;
            }
        }

        if (!found) return 0;

        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + arr[i];

        // Coordinate Compression
        vector<int> comp = pre;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        int m = comp.size();
        vector<int> bit(m + 1, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                idx -= idx & (-idx);
            }
            return ans;
        };

        long long ans = 0;

        for (int x : pre) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

            // Count previous prefix sums < current prefix sum
            ans += query(idx - 1);

            update(idx);
        }

        return ans;
    }
};