class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();

        // for(int x : nums){
        //     set.insert(nums[i]);
        // }

        int i=0;
        long long sum =0,mx = 0;
        for(int j =0;j<n;j++){
            while(st.count(nums[j])){
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                mx = max(mx,sum);
                sum-=nums[i];
                
                st.erase(nums[i]);
                i++;
            }
        }
        return mx;
    }
};