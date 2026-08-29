class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            int mn = INT_MAX;
            int id = -1;
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    if(nums[j]<mn){
                        mn = nums[j];
                        id = j;
                    }
                }
            }
            if(id!=-1){
                swap(nums[i],nums[id]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};