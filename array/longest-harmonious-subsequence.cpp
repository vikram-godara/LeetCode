class Solution {
public:
    int findLHS(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int>fre;
        for(int x : nums){
            fre[x]++;
        }
        int ans=0;
        for(auto  x : fre){
            int y = x.first;
            if(fre.find(y+1)!=fre.end()){
                ans = max(ans,fre[y]+fre[y+1]);
            }
        }
        return ans;
    }
};