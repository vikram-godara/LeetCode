class Solution {
public:
    int n;
    int maxRotateFunction(vector<int>& nums) {
        n = nums.size();
        // Key Idea ->
        // Let:
        // F(0)=0⋅nums[0]+1⋅nums[1]+⋯+(n−1)⋅nums[n−1]
        // Let total sum of array = S
        // Then:

        // F(k)=F(k−1)+S−n⋅nums[n−k]

        // F(k)=F(k−1)+S−n⋅nums[n−k]
        // F(0)=0a+1b+2c+3d
        // F(1)=0d+1a+2b+3c
        // both compare f0 and  f1 a,b,c increase by 1 and d is decreased
        //
        long long totalsum = 0;
        long long f0 = 0;
        // for(auto x : nums) totalsum +=x;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
            f0 += (i * nums[i]);
        }
        long long ans = f0;
        for (int k = 1; k < n; k++) {
            f0 = f0 + totalsum - (long long)n * nums[n - k];
            ans = max(ans, f0);
        }
        return ans;

        // O(n²) solution//

        // int maxs = INT_MIN;
        // for(int i=0;i<n;i++){
        //    int sum=0;
        //    int k=0;
        //    for(int j=n-i;j<n;j++){
        //     sum+=(k*nums[j]);
        //     k++;
        //    }
        //    for(int j=0;j<n-i;j++){
        //     sum+=(k*nums[j]);
        //     k++;
        //    }
        //    maxs = max(maxs,sum);
        // }
        // return maxs;
    }
};