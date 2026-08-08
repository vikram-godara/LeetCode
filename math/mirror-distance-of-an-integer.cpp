class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        int rev =0;
        while(n>0){
            rev = rev*10 + n%10;
            n/=10;
        }
        int ans = abs(num-rev);
        return ans;
    }
};