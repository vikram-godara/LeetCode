class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int len =nums[0];
        for(int i=0;i<n;i++){
            len = max(len,i+nums[i]);
            if(i==len)break;
            
        }
        return (len>=n-1);
    }
};