class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<k){
                cnt++;
                mp[nums[i]]++;
            }
            else return cnt;
        }
        return {};
    }
};