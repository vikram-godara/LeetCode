class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        //needs consecutive elements of array after incre...

        //how?--> need dp of states for increment and check 
        //how dp implement ?

        ranges::sort(nums); // 1,2,3,4,5

        unordered_map<int,int>dp; //dp[x] = x; is main concept 
        int ans=0;

        for(int x : nums){
            dp[x+1] = max(dp[x+1] , dp[x]+1);
            dp[x] = max(dp[x] , dp[x-1]+1);

            ans = max({ans,dp[x+1] , dp[x]});
        }

        return ans;
    }
};