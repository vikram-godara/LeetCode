class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        set<int>st;
        for(auto &s1 : series1){
            st.insert(s1[0]);
        }
        for(auto &s2 : series2){
            st.insert(s2[0]);
        }
        int i=0,j=0;
        int n = series1.size(),m = series2.size();
        for(int t : st){
            while(i<n && series1[i][0]<t)i++;
            while(j<m && series2[j][0]<t)j++;

            int x = (i<n ? series1[i][1] : 0);
            int y = (j<m ? series2[j][1] : 0);
            ans.push_back({t,x+y});
        }
        return ans;
    }
};