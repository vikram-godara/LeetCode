class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mx = INT_MAX;
        for(int i=0;i<cost.size();i++){
            if(cost[i]<mx){
                mx = cost[i];
            }
            else cost[i] = mx;
        }
        return cost;
    }
};