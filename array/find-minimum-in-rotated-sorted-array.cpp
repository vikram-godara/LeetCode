class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mn = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[r]) {
                mn = min(mn,nums[l]);
                l = mid+1;
            }
            else{
               mn = min(mn,nums[mid]);
               r = mid-1;
            }
        }
        return mn;
    }
};