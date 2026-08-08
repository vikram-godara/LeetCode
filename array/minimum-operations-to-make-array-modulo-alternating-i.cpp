class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int  n = nums.size();
        vector<int>even(k,0),odd(k,0);
        for(int i=0;i<n;i++){
            int rem= nums[i]%k;
            for(int r = 0;r<k;r++ ){
                int d = abs(rem-r);
                int cost = min(d,k-d);
                if(i%2==0)even[r]+=cost;
                else odd[r]+=cost;
            }
        }
        int ans = INT_MAX;
        for(int x = 0 ;x<k;x++){
            for(int y=0;y<k;y++){
                if(x!=y){
                    ans = min(ans,even[x] + odd[y]);
                }
            }
        }
        return ans;
    }
};