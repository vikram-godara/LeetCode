class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans =0;
        if(n<=8){
            return n;
        }
        int cnt =1;
        while(n!=0){
            if(n>8){
                ans = ans + 8*cnt;
                cnt++;
                n = n-8;
            }
            else {
                ans = ans + (n*cnt);
                n=0;
            }

        }
        return ans;


        
    }
};