class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>ans = { };
        for(int i=0;i<n-1;i++){
            if(nums[i+1] != nums[i]+1){
                ans.push_back(nums[i]+1);
                nums[i] = nums[i]+1;
                i--;
            }
        }
        return ans;
    }
};