class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN, cnt1 = 0, cnt0 = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 1) cnt1++;
            else cnt0++;

            while (cnt0 > k) {
                if (nums[i] == 0) {
                    cnt0--;
                }
                else{
                    cnt1--;
                }
                i++;
            }
            ans = max(ans, cnt1 + cnt0);
        }
        return ans;
    }
};