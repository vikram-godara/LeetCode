class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        int odd = 0,even=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2) odd++;

            while(odd>k){
                if(nums[i]%2){
                    odd--;
                }
                i++;
                even=0;
            }
            if(odd == k) {
                while(i<=j && nums[i]%2 ==0 ){
                    i++;
                    even++;
                }
                ans+=(even+1);
            }

        }
        return ans;
    }
};