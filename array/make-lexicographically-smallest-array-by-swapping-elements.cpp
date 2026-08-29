class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        int n = nums.size();
        for(int i=0;i<n;i++)v.push_back({nums[i],i});

        sort(v.begin(),v.end());

        int l = 0;
        while(l<n){
            int r =l;
            while(r+1<n && (v[r+1].first - v[r].first)<=limit) r++;
            vector<int>idxs;
            for(int i = l;i<=r;i++){
                idxs.push_back(v[i].second);
            }
            sort(idxs.begin(),idxs.end());

            for(int i =l;i<=r;i++){
                nums[idxs[i-l]] = v[i].first;
            }
            l=r+1;
        }
        return nums;
    }
};