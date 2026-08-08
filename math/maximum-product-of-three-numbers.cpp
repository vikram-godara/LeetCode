class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n-1]*nums[n-2]*nums[n-3];
        
        ans = max(ans,nums[n-1]*nums[n-2]*nums[0]);
        ans = max(ans,nums[n-1]*nums[1]*nums[0]);
        return ans;
    }
};