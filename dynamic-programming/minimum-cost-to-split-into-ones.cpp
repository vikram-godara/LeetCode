class Solution {
public:
    int minCost(int n) {
        //simple sol.
        // x = 1 + (x-1);

        return n*(n-1)/2;
        //partions of number
        // vector<int>dp(n+1,0);
        // dp[0] = 1;
        
        // for(int i=1;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         dp[j]+=dp[j-i];
        //     }
        // }
        
        // return dp[n];
    }
};