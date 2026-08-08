class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r= n-1;
        set<int>st(nums.begin(),nums.end());
        vector<int>ans (st.begin(),st.end());
        // while(l<r){
        //     int mid = l + (r-l)/2;
        //     if(nums[mid]>nums[r]){
        //         l= mid+1;
        //     }
        //     else r= mid;
        // }
        return *st.begin();
    }
};