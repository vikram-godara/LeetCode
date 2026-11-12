class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1=1,cnt0=1;
        int n = nums.size();
        int ans1 = 1 ,ans2 =1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt1++;
            }
            else {
                ans1 = max(ans1,cnt1);
                cnt1 = 1;
            }

            if(nums[i]<nums[i-1]){
                cnt0++;
            }
            else {
                ans2 = max(ans2,cnt0);
                cnt0 = 1;
            }
        }
        ans1 = max(ans1,cnt1);
        ans2 = max(ans2,cnt0);
        return max(ans1,ans2);
    }
};