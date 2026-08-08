class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        int m = s.size();
        char p = x +'0';
        int cnt=0;
        bool ans = true;
        if(s[0]==p) ans = false;
        for(int i=1;i<m;i++){
            if(s[i]==p)cnt++;
        }
        if(ans && cnt>0)return true;
        else return false;
    }
};