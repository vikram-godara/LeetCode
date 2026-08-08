class Solution {
public:
    int jump(vector<int>& nums) {
        int n  = nums.size();
        int len =0;
        int j=0,c=0;
        for(int i=0;i<n-1;i++){
            len = max(len,i+nums[i]);
            if(i==c){
                
                j++;
                c = len;
            }
            
        }
        return j;
    }
};