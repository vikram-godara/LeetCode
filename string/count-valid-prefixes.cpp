class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int c1 = 0,c0=0;
            for(int j = 0;j<=i;j++){
                
                if(s[j] =='0')c0++;
                else c1++;

                
            }
            if(abs(c1-c0)<=1) cnt++;
        }
        return cnt;
    }
};