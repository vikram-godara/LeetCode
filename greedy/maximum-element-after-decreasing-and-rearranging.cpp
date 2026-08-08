class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        // bool oneExist = false;

        // for(int i=0;i<n;i++){
        //     if(nums[i]==1){
        //         swap(nums[0],nums[i]);
        //         oneExist = true;
        //         break;
        //     }
        // }
        // int mn = *min_element(nums.begin(),nums.end());
        // if(!oneExist){
        //     for(int i=0;i<n;i++){
        //         if(mn == nums[i]){
        //             swap(nums[i],nums[0]);
        //             nums[0] =1;
        //         }
        //     }
        // }
        // vector<pair<int,int>>v;
        sort(nums.begin(),nums.end());
        nums[0] = 1;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>1){
                nums[i] = nums[i-1]+1;
            }
        }
        int mx = *max_element(nums.begin(),nums.end());
        return mx;
    }
};