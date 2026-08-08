class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();

        int cnt=0;

        int ps=0;
        int pg=0;
        while(ps<m && pg<n){
           if(s[ps]>=g[pg]){
            ps++;
            pg++;
            cnt++;
           }
           else
            ps++;
        }
        // for(int i=0;i<n;i++){
        //     if(g[i]==s[i])cnt++;
        // }
        return cnt;
    }
};