class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        //** for the brute force  **//


        // sort(nums.begin(),nums.end()); // index change after sort.
        // if (n <= 2)
        //     return -1;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         if (nums[i] == nums[j]) {
        //             for (int k = j+1; k < n; k++) {
        //                 if (nums[j] == nums[k]) {
        //                     int diff = abs(i - j) + abs(j - k) + abs(k - i);
        //                     ans = min(ans, diff);
        //                 }
        //             }
        //         }
        //     }
        // }
        // if (ans == INT_MAX)
        //     return -1;
        // return ans;

        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++)m[nums[i]].push_back(i);

        if(n<=2)return -1;
        for(auto & it : m){
            vector<int>&v = it.second;
            if(v.size()<3)continue;
            for(int i=0;i<v.size()-2;i++){
                int d = 2*(v[i+2]-v[i]);
                ans = min(ans,d);
            }
        }
        return (ans ==INT_MAX ? -1 : ans);
    }
};