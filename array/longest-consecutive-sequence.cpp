class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
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