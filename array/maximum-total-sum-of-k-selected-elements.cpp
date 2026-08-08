class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long  sum =0;
        vector<int>a;
        for(int i=n-1 ;i>=(n-k);i--){
            a.push_back(nums[i]);
            sum+=nums[i];
        }
        for(int i=0;i<a.size();i++){
            if(mul>1){
                sum+= 1LL * a[i] * (mul-1);
                mul--;
            }
            
        }
        return sum;
    }
};