class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string s="";
        // int n=strs.size();
        // for(int i=0;i<n-1;i++){
        //     string p="";
        //     for(int j=0;j<strs[i].length();j++){
        //         if(strs[i][j]==strs[i+1][j]){
        //             p+=strs[i][j];
        //         }
        //     }
        //     s=max(s,p);//logic error
        // }
        // return s;
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
            if (prefix == "") break;
        }
        return prefix;
    }
};