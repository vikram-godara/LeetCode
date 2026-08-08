class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(auto c : text) mp[c]++;
        int ans = INT_MAX;
        string a = "balloon";
        unordered_map<char,int>v={
            {'b',1},
            {'a',1},
            {'l',2},
            {'o',2},
            {'n',1}
        };
        vector<int>arr;
        for(int i=0;i<a.size();i++){
            if(mp.count(a[i])){
                int x = mp[a[i]] / v[a[i]];
                arr.push_back(x);
            }
            else arr.push_back(0);
        }
        return *min_element(arr.begin(),arr.end());
    }
};