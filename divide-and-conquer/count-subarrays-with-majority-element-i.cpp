class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int l = i;
        //         int r = j;
        //         int length = r-l+1;
        //         int count=0;
        //         for(int k = l;k<=r;k++){
        //             if(nums[k] == target)count++;
        //         }
        //         if(2*count>length)subarray++;
        //     }
        // }
       int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) cnt++;

                int len = j - i + 1;
                if (2 * cnt > len) ans++;
            }
        }

        return ans;
    }
};