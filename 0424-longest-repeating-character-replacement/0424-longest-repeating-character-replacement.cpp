class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,vector<int>>mp;
        for (int i=0;i<n;i++){
            mp[s[i]].push_back(i+1);
        }
        int ans = INT_MIN;
        for(auto &[x,v] : mp){
            int m = v.size();
            int r = k;
            int final = INT_MIN;
            int j=0;
            int cnt=0;
            for(int i=0;i<m;i++){
                if(i>0)cnt+= v[i]-v[i-1]-1;
                while(cnt>k && j<i){
                    int d = v[j+1]-v[j]-1;
                    if(d>0) cnt-=d;
                    j++;
                }
                int len = v[i]-v[j]+1 + k-cnt;
                len = min(len,n);
                final = max(final,len);
            }
            ans = max(ans,final);
        }
        return ans;
    }
};