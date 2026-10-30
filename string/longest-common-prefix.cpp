class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        if(strs.empty()) return "";
        if(n==1) return strs[0];
        int i=0;
        string s="";
        for(i=0;i<min(strs[0].size(),strs[n-1].size());i++){
            if(strs[0][i] == strs[n-1][i]) s += strs[0][i];
            else break;
        }
        return s;
        
    }
};