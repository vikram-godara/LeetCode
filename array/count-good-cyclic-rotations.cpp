class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        long long  l=0,r=0;
        if(n==2) {
            if(nums[0]==nums[1]) return 0;
            else return 1;
        }
        for(int i = 0;i<n/2;i++){
            l+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            r+=nums[i];
        }
        int mid = n/2;
        for(int i=0;i<n;i++){
            if(l>r) cnt++;
            l= l-nums[i]+nums[(i+mid)%n];
            r = r+nums[i]-nums[(i+mid)%n];
           
        }
        // for(int i = 0;i<n/2;i++){
        //     l = l-nums[mid+i]+nums[i];
        //     r = r+nums[mid+i]-nums[i];
        //     if(l>r)cnt++;
        // }
        return cnt;
    }
};