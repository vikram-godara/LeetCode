class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        long long mini = -4e18;
        long long ans = mini;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,mini));

        for(int i=0 ;i<=n;i++) dp[0][i] =0;
        
        for(int j =1;j<=m;j++){
            deque<int>dq;
            for(int k=1;k<=n;k++){
                dp[j][k] = dp[j][k-1];
               int add = k-l;
                if(add>=0){
                    long long val= dp[j-1][add] - prefix[add];
                    while(!dq.empty()&& dp[j-1][dq.back()] - prefix[dq.back()] <=val ) dq.pop_back();

                    dq.push_back(add);
                }
                while(!dq.empty() && dq.front() <k-r) dq.pop_front();

                if(!dq.empty()) {
                    dp[j][k] = max(dp[j][k] , prefix[k] + (dp[j-1][dq.front()] - prefix[dq.front()]));
                }
            }
            ans = max(ans,dp[j][n]);
        }
        // long long ans = mini;
        // for(int i=1;i<=m;i++){
        //     ans =max(ans,dp[i][n]);
        // }
        return ans;
    }
};