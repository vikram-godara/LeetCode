class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        // int num  = nums.size();
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         nums[i] = 2*nums[i+1];
        //         nums.erase(nums.begin()+i+1);
        //         i = -1;
        //     }
        // }
        


        //use stack to make complexcity by O(n)
        vector<long long>ans;
        for(int x:nums){
            long long y = x;
            while(!ans.empty() && ans.back()==y){
                // ans.push_back(2*x);
                ans.pop_back();
                y*=2;
            }
            ans.push_back(y);
            
        }
        // vector<long long >ans;
        // for(int i=0;i<nums.size();i++){
        //     ans.push_back(nums[i]);
        // }
        // vector<long long> final_ans(ans.begin(), ans.end());
        return ans;
    }
};