class Solution {
public:
    bool consecutiveSetBits(int n) {
      if(n==0) return   false;
        string res = "";
        int cnt=0;
        while(n>0){
            if((n&3) == 3 ) cnt++;
            n>>=1;
        }
        return cnt==1;
    }
};