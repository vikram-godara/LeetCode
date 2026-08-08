class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(),cost.rend());
        int sum = accumulate(cost.begin(),cost.end(),0);
        int mincost = sum;
        for(int i=2;i<n;i+=3){
            mincost-=cost[i];
        }
        return mincost;

    }
};