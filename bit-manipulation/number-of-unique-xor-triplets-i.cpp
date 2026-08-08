class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==2) return 2;
        if(n==1) return 1;
        

        // another value have the nc3 but duplicates comes so brute force comes TLE
        // so another solution is ?

        //use patter for the n>=3 is 0 to 2^k -1 is the answer is depend on msb of n.
        int pos = 0;
        int x = n;

        while (x > 1) {
            x >>= 1;
            pos++;
        }

        // Return 2^(pos+1)
        return 1 << (pos + 1);
    }
};