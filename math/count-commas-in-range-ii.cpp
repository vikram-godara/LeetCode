class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999) return 0;
        return n-999;
    }
};