class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        // int m = queries.size();
        // vector<int> ans;
        // for(auto x : queries){
        //     int a = x;
        //     int idx =INT_MAX;
        //     bool f = false ;
        //     for(int i=0;i<n;i++){
        //         if(nums[i]==nums[a] && i!=a){
        //             int l = abs(a-i);
        //             idx = min(idx,min(l,n-l));
        //             f = true;
        //         }
        //     }
        //     if(f) ans.push_back(idx);
        //     else ans.push_back(-1);
        // }
        // return ans;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);

        vector<int> ans;
        for(int q : queries){
            auto &v = mp[nums[q]];
            if(v.size() == 1){
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(v.begin(), v.end(), q);
            int idx = it - v.begin();

            int left = (idx - 1 + v.size()) % v.size();
            int right = (idx + 1) % v.size();

            int d1 = abs(v[left] - q);
            int d2 = abs(v[right] - q);

            int res = min(min(d1, n - d1), min(d2, n - d2));
            ans.push_back(res);
        }
        return ans;
    }
};