class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        unordered_set<string>st;
        for(string c : wordDict) st.insert(c);
        vector<int>dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j =0;j<i;j++){
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};