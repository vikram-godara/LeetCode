class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt1++;
            else{
                ans = max(ans,cnt1);
                cnt1=0;
            } 
        }
        ans = max(ans,cnt1);
        return ans;
    }
};