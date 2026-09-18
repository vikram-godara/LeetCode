class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb ==n || nums[lb] != target) return {-1,-1};
        int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin() -1;
        // int l =0,h = n-1;
        // while(l<=r){
        //     int m = l + (r-l)/2;
        //     if(nums[m]<=)
        // }
        return {lb,ub};
    }
};