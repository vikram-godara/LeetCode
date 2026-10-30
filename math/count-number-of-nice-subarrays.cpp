class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;
        int odd = 0,even =0;
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2) odd++;
            while(odd>k && i<n ){
                if(nums[i]%2) odd--;
                i++;
                even=0;
            }
            if(odd==k){
            while(i<=j && nums[i]%2 ==0){
                even++;
                i++;

            }
            cnt+=(even+1);
        }
        }
        
        return cnt;
    }
};