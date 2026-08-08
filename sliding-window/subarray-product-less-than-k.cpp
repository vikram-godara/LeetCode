class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt =0;
        int n = nums.size();
        int mul =1;
        for(int i=0;i<n;i++){
            mul*=nums[i];
            if(mul<k) cnt++;
            for(int j=i+1;j<n;j++){
                mul*=nums[j];
                if(mul<k) cnt++;
                if(mul>=k) break;
            }
            mul =1;
        }
        return cnt;
    }
};