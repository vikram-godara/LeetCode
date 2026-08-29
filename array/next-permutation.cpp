class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int mx = *max_element(nums.begin(),nums.end());
        if(nums[0]==mx){
            sort(nums.begin(),nums.end());
            for(int x : nums) cout<<x<<" ";
            cout<<endl;
            return;
        }
        else{
            sort(nums.begin()+1,nums.end(),greater<int>());
            for(int x : nums) cout<<x<<" ";
            cout<<endl;
            return;
        }
    }
};