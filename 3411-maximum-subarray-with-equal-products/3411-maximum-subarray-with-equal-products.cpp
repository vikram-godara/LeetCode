class Solution {
public:
    int lcmf(int a, int b) { 
        return (a / __gcd(a, b)) * b;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int length = 0;
        
        for (int i = 0; i < n; i++) {
            long long product = 1;
            int gcd = 0;
            int lcm = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];
                if(product>25200) break;
                gcd = __gcd(gcd, nums[j]);
                lcm = lcmf(lcm, nums[j]);
                if (product == 1LL * gcd * lcm) {
                    length = max(length, j - i + 1);
                }
            }
        }
        return length;
    }
};