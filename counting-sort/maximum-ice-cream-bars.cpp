class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        int cnt=0;
        sort(costs.begin(),costs.end());
        for(auto x : costs){
            ans+=x;
            if(ans>coins){
                return cnt;
            }
            cnt++;
        }

        return cnt;
    }
};