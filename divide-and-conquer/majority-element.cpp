class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt =1;
        int num = nums[0];   
        for(int i = 1;i<n;i++){
            if(num == nums[i]) cnt++;
            else if(num!=nums[i]) cnt--;
            
            else if(cnt==0) num = nums[i];
        }
        return num;
    }
};