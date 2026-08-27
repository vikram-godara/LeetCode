class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>ans;
        for(int x : nums) mp[x]++;
        vector<pair<int,int>>v;
        for(auto &[k,val]: mp) v.push_back({k,val});

        sort(v.begin(),v.end() , [](auto  &a ,auto &b){
            return a.second>b.second;
        });

        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;

    }
};