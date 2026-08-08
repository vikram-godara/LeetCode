class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // int jumps=0;
        int n=nums.size();
        // int l=0,r=1;
        // while(l<n && r<n){
        //     if(abs(nums[r]-nums[l])<=target){
        //         jumps++;
        //         l=r;
        //         r++;                                                                
        //     }
        //     r++;
        // }

        // return jumps;
        vector<int> dp(n, -1);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(dp[j] != -1 &&
                   abs(nums[i] - nums[j]) <= target) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];

    }
};