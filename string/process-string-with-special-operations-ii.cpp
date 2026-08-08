class Solution {
public:
    char processStr(string s, long long k) {
        // string res ="";
        // long long  l =0;
        // for(auto c : s){
        //     if(c>='a' && c<='z') l++;
        //     else if(c=='*'){
        //         // if(!res.empty()){
        //         //     res.pop_back();
        //         // }
        //         l = max(0,l-1);
        //     }
        //     else if(c=='#'){
        //         // res = res + res;
        //         l*=2;
        //     }
        //     else if(c=='%'){
        //         // reverse(res.begin(),res.end());
        //         // int l = 0;
        //         // int r = res.size()-1;
        //         // while(l<=r){
        //         //     swap(res[l],res[r]);
        //         //     l++;
        //         //     r--;
        //         // }
        //     }
        // }
        // if(l<=k) return '.';
         int n = s.size();

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = len[i] * 2;
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i]) return c;
            }
            else if (c == '*') {
                // k unchanged
            }
            else if (c == '#') {
                k %= len[i];
            }
            else { // '%'
                k = len[i] - 1 - k;
            }
        }

        return '.';

        
    }
};