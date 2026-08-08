class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=cost.size();
        long long  total=0;
        for(int x:cost)total+=x;
        vector<long long > keep(26,0);
        for(int i=0;i<n;i++){
            keep[s[i]-'a']+=cost[i];
        }
        long long  ans=LLONG_MAX;
        for(int i=0;i<26;i++){
            if(keep[i]>0){
                ans=min(ans,total-keep[i]);
            }
        }
        return ans;
    }
};