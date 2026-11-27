class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        string s1 = strs[0];
        string s2 = strs[1];

        string prefix = "";
        for(int i = 0;i<min(s1.size(),s2.size());i++){
            if(s1[i] == s2[i]) prefix+=s1[i];
            else break;
        }
        for(int i=2;i<n;i++){
            string temp ="";
            for(int j = 0;j<min(strs[i].size(),prefix.size());j++){
                if(strs[i][j] == prefix[j]){
                    temp+=prefix[j];
                }else break;
            }
            prefix = temp;
        }
        return prefix;
    }
};