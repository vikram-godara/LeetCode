class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        int n = items.size();
        vector<int>gf(n,0);
        
        for(int i=0;i<n;i++){
            
            int f = items[i][0];
            
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%f ==0) gf[i]++;
            }
        }
        vector<int>dp(budget+1,0);
        vector<int>ndp(budget+1);
        for(int i=0;i<n;i++){
            int p = items[i][1];
            int g = gf[i];
            ndp = dp;
            for(int j = 0;j<p;j++){
                
                // int maxs = (budget - j) / price;
                int best = -(int)1e9;
                for(int k = 0, cost = j;cost <= budget; k++, cost += p){
                    // int cost = k*price;
                    // int value = k+ g[i];
                    // s[j+cost] = max(s[j+ cost],dp[j]+ value);
                    if (k >= 1) {
                        ndp[cost] =max(ndp[cost],best+g+k);
                    }
                    best =max(best,dp[cost]- k);
                }
            }
            dp.swap(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};