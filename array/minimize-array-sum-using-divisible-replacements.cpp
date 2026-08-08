class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        // bool found=false;
        unordered_set<int>set(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int best=x;
            for(int j=1;j*j<=x;j++){
                if(x%j==0){
                    if(set.count(j)){
                        best = min(best,j);
                    }
                    int y=x/j;
                    if(set.count(y)){
                        best = min(best,y);
                    }
                }
            }
            sum+=best;
        }
        // if(found){
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]%2==0) sum+=p;
        //         else sum+=nums[i];
        //     }
        // }
        return sum;
        
    }
};