class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=s.length();
        string ans="";
        for(int i=0;i<k;i++){
            ans=s[i]+ans;
        }
        for(int i=k;i<n;i++){
            ans+=s[i];
        }
        return ans;
    }
};