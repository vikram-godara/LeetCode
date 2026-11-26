
class Solution {
public:
    using ll = long long;

    const ll mod1 = 1000000007;
    const ll mod2 = 998244353;
    const ll base = 131;

    vector<ll> h1, h2, p1, p2;

    bool check(int len) {
        int n = h1.size() - 1;

        unordered_map<ll, int> mp;

        for (int i = 0; i + len <= n; i++) {
            ll hash1 = (h1[i + len] - h1[i] * p1[len] % mod1 + mod1) % mod1;
            ll hash2 = (h2[i + len] - h2[i] * p2[len] % mod2 + mod2) % mod2;

            // Combine both hashes
            ll hash = hash1 * mod2 + hash2;

            mp[hash]++;
        }

        for (auto &it : mp) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * base % mod1;
            p2[i + 1] = p2[i] * base % mod2;

            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;
        }

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
