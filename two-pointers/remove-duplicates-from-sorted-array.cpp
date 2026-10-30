class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++){
             if(nums[i]!=nums[i-1]) arr.push_back(nums[i]);
        }
        nums = arr;
        return arr.size();
    }
};