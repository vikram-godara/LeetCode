class Solution {
public:

    bool prime(int x) {

        if (x <= 1)
            return false;

        if (x == 2)
            return true;

        if (x % 2 == 0)
            return false;

        for (int i = 3; i * i <= x; i += 2) {

            if (x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // store all indices divisible by divisor
        for (int i = 0; i < n; i++) {

            for (int d = 1; d * d <= nums[i]; d++) {

                if (nums[i] % d == 0) {

                    mp[d].push_back(i);

                    if (d != nums[i] / d)
                        mp[nums[i] / d].push_back(i);
                }
            }
        }

        queue<int> q;

        vector<int> vis(n, 0);

        unordered_set<int> usedPrime;

        q.push(0);

        vis[0] = 1;

        int jumps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return jumps;

                // left
                if (i - 1 >= 0 && !vis[i - 1]) {

                    vis[i - 1] = 1;

                    q.push(i - 1);
                }

                // right
                if (i + 1 < n && !vis[i + 1]) {

                    vis[i + 1] = 1;

                    q.push(i + 1);
                }

                // teleport
                if (prime(nums[i]) &&
                    !usedPrime.count(nums[i])) {

                    usedPrime.insert(nums[i]);

                    for (int idx : mp[nums[i]]) {

                        if (!vis[idx]) {

                            vis[idx] = 1;

                            q.push(idx);
                        }
                    }
                }
            }

            jumps++;
        }

        return -1;
    }
};