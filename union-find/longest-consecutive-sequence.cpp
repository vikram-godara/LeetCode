class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_map<int,int>mp;
        for(int x : nums) mp[x]++;
        int mx = INT_MIN;
        int cnt =0;
        for(int x : nums){
            int num = x;
            while(mp.count(num)){
                cnt++;
                num+=1;
            }
            mx = max(mx,cnt);
            cnt=0;
        }
        return mx;
    }
};