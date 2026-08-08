class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefixsum(nums.size() +1 ,0);
        prefixsum.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            prefixsum[i+1] = prefixsum[i] + nums[i];
        }
        int leftsum = 0,rightsum = 0;
        for(int i=0;i<nums.size();i++){
            leftsum = prefixsum[i];
            rightsum = prefixsum[nums.size()] - prefixsum[i+1];
            if(leftsum == rightsum) return i;
        }
        return -1;
    }
};