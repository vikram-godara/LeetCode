class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        vector<pair<int,int>>v;
        if(n==1){
            return {{intervals[0][0],intervals[0][1]}};
        }
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if((v[i].first<=v[i-1].second) &&(v[i-1].second<v[i].second)){
                ans.push_back({v[i-1].first,v[i].second});
            }
            else ans.push_back({v[i].first,v[i].second});
        }
        
        return ans;
    }
};