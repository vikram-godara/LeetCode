class Solution {
public:
    bool check (long long x ,vector<int>&monsters,vector<long long>&c){
        long long cur = x;
        for(int i=0;i<monsters.size();i++){
            if(cur+c[i]<monsters[i])return false;
            cur-=monsters[i];
            if(cur<0)cur=0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        auto add = make_pair(monsters,boosts);
        vector<long long>d(n+1,0);
        for(auto &b : boosts){
            d[b[0]] +=b[2];
            if(b[1]+1<n ) d[b[1]+1] -=b[2];
        }
        vector<long long>c(n,0);
        long long bonus=0;
        for(int i=0;i<n;i++){
            bonus +=d[i];
            c[i] = bonus;
        }
        long long l=0,r=0;
        for(int x : monsters) r+=x;
        while(l<r){
            long long m = l + (r-l)/2;
            if(check(m,monsters,c)) r = m;
            else l = m+1;
        }
        return l;
    }
        
};