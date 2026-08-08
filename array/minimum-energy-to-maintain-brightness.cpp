class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // int n = intervals.size();
        long long ans =0;
        long long l = intervals[0][0];
        long long r = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            long long a = intervals[i][0];
            long long b = intervals[i][1];

            if(a<=r+1){
                r=max(r,b);
            }
            else{
                ans+=(r-l+1);
                l=a;
                r=b;
            }
        }
        ans+=(r-l+1);
        long long need =(brightness+2)/3;
        return need*ans;
    }
};