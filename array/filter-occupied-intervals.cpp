class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        map<int, int> mp;
        int a = occupiedIntervals[0][0], b = occupiedIntervals[0][1];
        for (int i = 1; i < n; i++) {
            if (occupiedIntervals[i][0]<=b+1) {
                b = max(b,occupiedIntervals[i][1]);
            }
            else{
                mp[a]=b;
                a = occupiedIntervals[i][0];
                b = occupiedIntervals[i][1];
            }
        }
        mp[a] =b;
        map<int, int> mp1;
        for (auto& [key, val] : mp) {
            if (freeStart > val || key>freeEnd) {
                mp1[key] = val;
            }
           else{
               if(key<freeStart) mp1[key] = freeStart -1;
               if(val>freeEnd) mp1[freeEnd+1] =val;
           }
        }
        vector<vector<int>>ans;
        for(auto &[k,v]:mp1){
            ans.push_back({k,v});
        }
        return ans;
    }
};