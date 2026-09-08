class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int i=0,j=0;
        string res ;
        vector<string>substring;
        for(int i=0;i<n;i++){
            string r = "";
            for(int j = i;j<n;j++){
                r = r + s[j];
                substring.push_back(r);
                // int l = r.size();
                // bool ok = true;
                // for(int k=0;k<l/2;k++){
                //     if(r[k]!=r[l-k-1])ok = false;
                // }
                // if(ok){
                //     if(r.size()>res.size()) res = r;
                // }
            }
        }
        for(int i=0;i<substring.size();i++){
            int l = substring[i].size();
            bool ok = true;
            for(int k=0;k<l/2;k++){
               if(substring[i][k]!=substring[i][l-k-1])ok = false;
            }
            if(ok){
               if(substring[i].size()>res.size()) res = substring[i];
            }
        }
        
        return res;
    }
};