class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int n = discounts.size();
        int m = prices.size();
        double ans =0;
        int cnt =0;
        int len;
        if(n>=m){
            for(int i=0;i<m;i++){
                ans+=(prices[i]*(100.0-discounts[i])/100.0);
            }
        }
        else{
            len = n;
            for(int i=0;i<n;i++){
                ans+=(prices[i]*(100.0-discounts[i])/100.0);
            }
            for(int i = n;i<m;i++){
                ans+=prices[i];
            }
        }
        return ans;
    }
};