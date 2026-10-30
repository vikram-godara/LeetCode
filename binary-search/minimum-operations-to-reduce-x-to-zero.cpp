class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int op =-1;
        int target = 0;
        for(int x : nums)target+=x;
        int need = target-x;
        if(need<0) return -1;
        if(need==0) return n;
        for(j=0;j<n;j++){
            sum+=nums[j];
            while(sum>need){
                sum-=nums[i];
                i++;
            }
            if(sum == need) {
                op = max(op,j-i+1);
            }
        }
        if(op==-1) return -1;
        return n-op;
    }
};