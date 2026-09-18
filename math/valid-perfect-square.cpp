class Solution {
public:
    bool isPerfectSquare(int num) {
        int p = 1;
        for(int i=1;i<=INT_MAX;i++){
            if(i*p > num) break;
            if(i*p == num) return true;
            p++;
        }
        return false;
    }
};