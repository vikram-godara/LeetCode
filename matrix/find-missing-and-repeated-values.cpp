class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int>mp;
        int sum = 0;
        int duplicate;
        for(auto &q : grid){
            for(int &x : q) {
                mp[x]++;
                sum+=x;
                if(mp[x]>1){
                    duplicate = x;
                    mp[x]--;
                }
            }
        }
        int actualsum = n*n*(n*n+1)/2;
        int miss = actualsum -sum+duplicate;
        return {duplicate,miss};
    }
};