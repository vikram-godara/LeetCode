class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        // pair<string,string>p = {s,t};
        int a =0;
        int b = 0;
        for(char c: t){
            int p = a;
            int q = b;
            if(q<s.size() && s[q] == c)b=q+1;
            if(p<s.size())b = max(b,p+1);

            if(p<s.size() && s[p] == c) a = p+1;
        }
        return b == s.size();
        
    }
};