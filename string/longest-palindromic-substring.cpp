class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int i=0,j=0;
        string res ;
        for(int i=0;i<n;i++){
            string r = "";
            for(int j = i;j<n;j++){
                r = r + s[j];
                int l = r.size();
                bool ok = true;
                for(int k=0;k<l/2;k++){
                    if(r[k]!=r[l-k-1])ok = false;
                }
                if(ok){
                    if(r.size()>res.size()) res = r;
                }
            }
        }
        return res;
    }
};