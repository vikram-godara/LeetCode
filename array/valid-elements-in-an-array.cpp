class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> lf(n), rh(n),ans;
        lf[0] = -1;
        for (int i = 1; i < n; i++) {
            lf[i] = max(lf[i - 1], nums[i - 1]);
        }
        rh[n - 1] = -1;
        for (int i = n - 2; i >=0; i--) {
            rh[i] = max(rh[i + 1], nums[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1 || nums[i] > lf[i] || nums[i] > rh[i])
                ans.push_back(nums[i]);
        }

        return ans;
    }
};