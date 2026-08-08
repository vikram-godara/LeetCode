class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int l=queries.size();
        int div = 1e9+7;
        vector<int>mul(n,1);
        for(int i=0;i<l;i++){
            int idx = queries[i][0];
            while(idx<=queries[i][1]){
                mul[idx] = (int)((1LL*mul[idx]*queries[i][3])%div);
                if(mul[idx] < 0) mul[idx] +=div;
                idx+=queries[i][2];
            }
        }
        int ans = 0;
        for(int x=0;x<n;x++){
            nums[x] = (int)((1LL*nums[x]*mul[x])%div);
            ans  = ans^nums[x];
        }
        return ans;
    }
};