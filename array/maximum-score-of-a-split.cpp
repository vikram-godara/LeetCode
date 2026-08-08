class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long >su(n);
        su[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            su[i]=min((long long )nums[i],su[i+1]);
        }
    
    long long max=LLONG_MIN;
    long long pre=0;
    for(int i=0;i<n-1;++i){
        pre+=nums[i];
        long long sc = pre-su[i+1];
         if(sc>max)max=sc;
       }

    return max;
    }
};