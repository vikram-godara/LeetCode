class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1;
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (i < j && nums[j] > 1LL * nums[i] * k) {
                i++;
            }
            best = max(best, j - i + 1);
        }
        return n - best;
    }
};