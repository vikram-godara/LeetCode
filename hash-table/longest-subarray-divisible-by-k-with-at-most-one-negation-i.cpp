class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        // unordered_map<int,int>mp;
        // mp[0] = -1;
        // long long sum =0;
        // for(int j = 0;j<n;j++){
        //         sum+=nums[j];
        //         int d = sum%k;
        //         if(d<0) d+=k;
        //         if(mp.count(d)) {
        //             mx = max(mx,j-mp[d]);
        //         }
        //         else mp[d] = j;
        // }
        vector<int>ok(k,-1);
        for(int i=0;i<n;i++){
            // nums[i] *= -1;
            long long sum = 0;
            // unordered_map<int,int>mp;
            // mp.clear();
            // mp[0] = -1;
            // int cnt =0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                int x = (2LL* nums[j])%k;
                if(x<0) x+=k;
                ok[x] = i;
                int d = sum%k;
                if(d<0) d+=k;
                // if(mp.count(d)) {
                //     mx = max(mx,j-mp[d]);
                // }
                if(d==0 || ok[d] == i){
                    mx = max(mx,j-i+1);
                }
                // else mp[d] = j;
            }
            // nums[i]*=-1;
        }
        return mx;
    }
};