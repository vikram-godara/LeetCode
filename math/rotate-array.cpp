class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int shift = k%n;
        // vector<int>ans;
        // for(int i = n-shift;i<n;i++){
        //     ans.push_back(nums[i]);
        // }
        // for(int i=0;i<=n-shift-1;i++){
        //     ans.push_back(nums[i]);
        // }
        // nums = ans;

        reverse(nums.begin(),nums.begin()+n-shift);
        reverse(nums.begin()+n-shift,nums.end());
        reverse(nums.begin(),nums.end());
    }
};