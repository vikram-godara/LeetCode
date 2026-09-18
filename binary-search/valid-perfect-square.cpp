class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  p = 1;
        for(long long  i=1;i<=INT_MAX;i++){
            if(i*p > 1LL*num) break;
            if(i*p == 1LL*num) return true;
            p++;
        }
        return false;
    }
};