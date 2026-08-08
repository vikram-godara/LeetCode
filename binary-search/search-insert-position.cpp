class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        bool inArray = false;
        for(int i=0;i<n;i++){
            if(nums[i]>=target){
               return i;
            }
        }
         return n;
    //    int low = 0;
    //     int high = nums.size() - 1;

    //     while (low <= high) {
    //         int mid = low + (high - low) / 2; // Prevents overflow

    //         if (nums[mid] == target) {
    //             return mid;
    //         } else if (nums[mid] < target) {
    //             low = mid + 1;
    //         } else {
    //             high = mid - 1;
    //         }
    //     }

    //     // When the loop ends, 'low' is the correct insertion index.
    //     return low;
    }
};