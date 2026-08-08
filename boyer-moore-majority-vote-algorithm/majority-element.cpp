class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int key =nums[0];
        int maxcount =1;
         int currCount =1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                currCount++;
            }
            else {
                if(currCount>maxcount){
                    maxcount = currCount;
                    key = nums[i-1];
                }
                currCount =1;
            }
        }
        if(currCount>maxcount)key =nums[n-1];
        return key ;
        //return nums[nums.size() / 2]; -> this is for sort and then return size/2 element direct 
    
    }
};