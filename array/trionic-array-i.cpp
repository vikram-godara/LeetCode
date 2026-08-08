class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int n = nums.size();
        if (n < 4)
            return false;
        
        for (int p = 1; p <= n - 3; p++) {
            for (int q = p + 1; q <= n - 2; q++) {
                bool firstOK = true;
                for (int i = 0; i < p; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        firstOK = false;
                        break;
                    }
                }
                if (!firstOK)
                    break;
                bool secondOK = true;
                for (int i = p; i < q; i++) {
                    if (nums[i] <= nums[i + 1]) {
                        secondOK = false;
                        break;
                    }
                }
                if (!secondOK)
                    continue;

                bool thirdOK = true;
                for (int i = q; i < n - 1; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        thirdOK = false;
                        break;
                    }
                }
                if (thirdOK)
                    return true;
            }
        }
        return false;
    }
};