class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(string s: strs){
            string x = s;
            sort(x.begin(),x.end());
            mp[x].push_back(s);
        }
        for(auto&[k,v]:mp){
            ans.push_back(v);
        }
        return ans;

    }
};