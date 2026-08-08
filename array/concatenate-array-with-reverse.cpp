class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>newa=nums;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            newa.push_back(nums[i]);
        }
        return newa;
    }
};