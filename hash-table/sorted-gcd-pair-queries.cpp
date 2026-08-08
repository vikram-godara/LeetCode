#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxA = 50000;

        vector<int> freq(maxA + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(maxA + 1, 0);

        for (int g = 1; g <= maxA; g++) {
            for (int m = g; m <= maxA; m += g) {
                cnt[g] += freq[m];
            }
        }

        vector<long long> exact(maxA + 1, 0);

        for (int g = maxA; g >= 1; g--) {
            long long total = cnt[g] * (cnt[g] - 1) / 2;

            for (int m = 2 * g; m <= maxA; m += g) {
                total -= exact[m];
            }

            exact[g] = total;
        }

        // prefix sum of counts
        vector<long long> pref(maxA + 1, 0);
        for (int g = 1; g <= maxA; g++) {
            pref[g] = pref[g - 1] + exact[g];
        }

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = maxA, res = 1;

            while (l <= r) {
                int mid = (l + r) / 2;

                if (pref[mid] > q) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};