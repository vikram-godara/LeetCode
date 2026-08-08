class Solution {
public:
    static constexpr int mod = 1e9+7;
    int qpow(int x,int y){
        int res =1;
        for(;y;y>>=1){
            if(y&1){
                res = 1ll * res * x%mod;
            }
            x = 1ll* x * x%mod;
        }
        return res;
    }
    int dfs(vector<vector<int>>&g ,int x ,int f){
        int mx =0;
        for(auto &y : g[x]){
            if(y==f) continue;
            mx = max(mx,dfs(g,y,x) +1);
        }
        return mx;
       

    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
       int n = edges.size()+1;
       vector<vector<int>>g(n+1);
       for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
       }
       int mx  = dfs(g,1,0);
       return qpow(2,mx-1);
    }
};