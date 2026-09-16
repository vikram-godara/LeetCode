class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        for(char c : s) mp[c]++;
        vector<pair<char,int>>v;
        for(auto &[k,vi] : mp) v.push_back({k,vi});

        sort(v.begin(),v.end(), [](auto &a ,auto &b){
            return a.second>b.second;
        });
        string ans ="" ;
        for(auto x : v){
            ans+=(string(x.second,x.first));
        }
        return ans;
    }
};