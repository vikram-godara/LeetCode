class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        // unordered_map<int,int>mp;
        // for(int x : nums) mp[x]++;
        int mx = INT_MIN;
        // for(int x : nums){
        //     if(!mp.count(x-1)){
        //         int num = x;
        //         int cnt =0;
        //         while(mp.count(num)){
        //             cnt++;
        //             num++;
        //         }
        //         mx = max(mx,cnt);
        //     }
        // }
        // return mx;
        unordered_set<int>st;
        for(int x : nums) st.insert(x);

        for(int x : st){
            if(!st.count(x-1)){
                int cnt=0;
                while(st.count(x)){
                    cnt++;
                    x++;
                }
                mx = max(mx,cnt);
            }
        }
        return mx;
    }
};