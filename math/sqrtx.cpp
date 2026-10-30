class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l = 1, h=x;
        int ans = 1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(1LL* mid*mid<=x) {
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        return ans;
    }
};