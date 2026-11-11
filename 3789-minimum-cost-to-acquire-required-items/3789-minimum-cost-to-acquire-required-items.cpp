class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long  ans = LLONG_MAX;

        //frst random 
        ans = min(ans,1LL* cost1*need1+ 1LL* cost2*need2);

        //costboth
        ans = min(ans,1LL*costBoth*max(need1,need2));

        //mixed 
        if(need1>=need2){
            ans = min(ans,1LL*costBoth*need2+1LL*(need1-need2)*cost1);
        }
        else ans = min(ans,1LL*costBoth*need1 + 1LL*(need2-need1)*cost2);
        
        return ans;
    }
};