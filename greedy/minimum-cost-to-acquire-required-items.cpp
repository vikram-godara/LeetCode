class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long r=(long long)need1*cost1 + (long long)need2*cost2;
        long long k=min(need1,need2);
        long long m=max(need1,need2);

        long long o1=r;
        long long o2 = (long long)k*costBoth+(long long)(need1-k)*cost1+(long long)(need2-k)*cost2;
        long long o3=(long long)m*costBoth;

        return min({o1,o2,o3});
    }
};