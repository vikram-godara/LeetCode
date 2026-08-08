class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n+1, 0);
        for(int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + nums[i];

        long long total = prefix[n];

        vector<long long> suffix(n+1, 1);

        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == 0) {
                suffix[i] = 0;
            } else {
                if(suffix[i+1] > total / nums[i])
                    suffix[i] = total + 1;
                else
                    suffix[i] = suffix[i+1] * nums[i];
            }
        }

        for(int i = 0; i < n; i++) {
            long long leftSum = prefix[i];
            long long rightProduct = suffix[i+1];

            if(leftSum == rightProduct)
                return i;
        }

        return -1;
    }
};