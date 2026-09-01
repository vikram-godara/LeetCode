class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>arr(n,-1);
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            int mx = *max_element(prices.begin()+i,prices.end());
            if(mx>prices[i]){
                ans = max(ans,mx-prices[i]);
            }
        }
        return (ans==INT_MIN? 0: ans);
    }
};