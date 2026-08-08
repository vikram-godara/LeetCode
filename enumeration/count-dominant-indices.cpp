class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            float avg = 0;
            for(int j = i+1 ;j<n;j++){
                avg+=nums[j];
            }
            int num = n-i-1;
            avg = avg / num;
            if(nums[i]>avg){
                count++;
            }
        }
        return count;
    }
};