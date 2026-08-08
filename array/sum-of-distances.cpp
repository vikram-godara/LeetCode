class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto& p : mp) {
            vector<int>& idx = p.second;

            // for (int i = 0; i < idx.size(); i++) {
            //     long long sum = 0;

            //     for (int j = 0; j < idx.size(); j++) {
            //         if (i != j) {
            //             sum += abs(idx[i] - idx[j]);
            //         }
            //     }

            //     ans[idx[i]] = sum;
            // }
            int k = idx.size();

            vector<long long> pref(k);
            pref[0] = idx[0];

            for (int i = 1; i < k; i++) {
                pref[i] = pref[i - 1] + idx[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if (i > 0)
                    left = 1LL * idx[i] * i - pref[i - 1];

                if (i < k - 1)
                    right =(pref[k - 1] - pref[i]) - 1LL * idx[i] * (k - i - 1);

                ans[idx[i]] = left + right;
            }
        }

        return ans;
        }
    };