class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        if(n==1){
            return {{intervals[0][0],intervals[0][1]}};
        }
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        for(int i=1;i<n;i++){
            if((intervals[i][0]<=intervals[i-1][1])&&(intervals[i][1]>=intervals[i-1][1])){
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1],intervals[i-1][1]);
               
            }
            else{
                
                ans.push_back(intervals[i-1]);
            }
        }
        ans.push_back(intervals[n-1]);
        return ans;
    }
};