class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int cnt =0;
        // float ratio = a/b;

        vector<int>even(n+1,0),odd(n+1,0);
        for(int i=0;i<n;i++){
            even[i+1] = even[i];
            odd[i+1] = odd[i];
            if(nums[i]%2) odd[i+1]++;
            else even[i+1]++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long x = even[j+1]-even[i];
                long long y = odd[j+1]-odd[i];
                if(y>0 && (1LL * b*x <= 1LL * a * y))cnt++;
            }
        }
        return cnt;
        
    }
};