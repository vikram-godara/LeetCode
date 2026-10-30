class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long gcdd = __gcd(nums[i],nums[j]);
                long long gcddd = pow(gcdd,2);
                long long  add = (1LL* nums[i]*nums[j])/(gcddd);
                ans  = max(ans,add);
            }
        }
        return ans;
    }
};