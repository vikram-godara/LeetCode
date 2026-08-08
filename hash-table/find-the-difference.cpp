class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.size();
        int m = t.size();

        // string ans;
        // if(n>m){
        //     ans = s;
        //     s=t;
        // }
        // else{
        //     ans = t;
        // }
        // int p = min(n,m);
        // for(int i=0;i<p;i++){
        //     ans = ans-s[i];
        // }
        // return ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i])
                return t[i];
        }

    return t.back();
    }
};