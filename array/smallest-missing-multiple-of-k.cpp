class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int max=0;
        for(int i=k; ; i+=k){
            if(s.find(i)==s.end())
               return i;
        } 
    }
};