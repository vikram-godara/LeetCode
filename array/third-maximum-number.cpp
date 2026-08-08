class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        
        int b=0;
        sort(nums.begin(),nums.end());
        int a = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]==a)continue;
            else if(nums[i]<a){
                a = nums[i];
                b++;
            }
            if(b==2)break;
        }
        if(b==1){
            a= nums[n-1];
        }
        // if(n==2)a= max(nums[0],nums[1]);
        return a;

    }
};