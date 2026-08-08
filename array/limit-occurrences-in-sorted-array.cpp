class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x : mp){
            int fre = min(k,x.second);
            while(fre--) ans.push_back(x.first);
        }
        return ans;
    }
};