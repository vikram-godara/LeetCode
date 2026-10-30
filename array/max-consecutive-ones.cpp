class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int mx=-1;
        for(int i=0;i<n;i++){
            if(nums[i] == 1) cnt++;
            else{
                mx =max(mx,cnt);
                cnt=0;
            }
        }
        mx =max(mx,cnt);
        return mx;
    }
};