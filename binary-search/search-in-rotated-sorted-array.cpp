class Solution {
public:
    int search(vector<int>& nums, int target) {
        // unordered_map<int,int>mp;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     mp[nums[i]] = i;
        // }
        // if(mp.count(target)){
        //     // return mp[target];
        // }
        // // return -1;

        int l = 0;
        int r = n-1;
        while(r>=l){
            int mid  = l + (r-l)/2;
            if(nums[mid] == target) return mid;

            if(nums[l]<=nums[mid]){
                if(nums[l]<= target && target <= nums[mid]){
                    r = mid-1;
                }
                else l = mid+1;
            }
            else {
                if(nums[mid] < target  && target <= nums[r]){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }
        return -1;
    }
};