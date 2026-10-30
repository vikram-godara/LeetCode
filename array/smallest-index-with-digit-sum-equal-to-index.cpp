class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int sum = 0;
            while(num>0){
                int d = num%10;
                sum+=d;
                num/=10;
            }
            if(sum==i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};