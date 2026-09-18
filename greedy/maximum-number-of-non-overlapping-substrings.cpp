class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(!mp.count(s[i])) mp[s[i]] = {i,i};
            else{
                // int l = mp[s[i]].first;
                // int r = mp[s[i]].second;
                // l = min(l,i);
                // r = max(r,i);
                // mp[s[i]] = {l,r};
                mp[s[i]].second = i;
            }
        }
        vector<string>substrings;
        int j = 0;
        while(j<n){
            char a = s[j];
            int l = mp[s[j]].first;
            int r = mp[s[j]].second;
            if(l==r) substrings.push_back(string(1,a));
            else{
                int len = r-l+1;
                string sub = s.substr(l,len);
                substrings.push_back(sub);
            }
            j++;
        }
        vector<pair<string,pair<int,int>>>finals;
        for(int i =0;i<substrings.size();i++){
            string sub = substrings[i];
            int l = mp[sub[0]].first;
            int r = mp[sub[0]].second;
            bool ans = true;
            for(int j=l;j<=r;j++){
                int x = mp[s[j]].first;
                int y = mp[s[j]].second;
                if(x<l){
                    ans = false;
                    break;
                }
                r = max(r,y);
            }
            if(ans) finals.push_back({s.substr(l,r-l+1),{l,r}});
        }
        sort(finals.begin(),finals.end(), [](auto &a ,auto &b){
            return a.second.second-a.second.first < b.second.second-b.second.first;
        });
        vector<pair<string,pair<int,int>>>selected;
        for(auto &x : finals){
            int l = x.second.first;
            int r = x.second.second;
            bool overloop = false;
            for(auto &y : selected){
                int l2 = y.second.first;
                int r2 = y.second.second;
                if(!(r<l2 || l>r2)){
                    overloop = true;
                    break;
                }
            }
            if(!overloop) selected.push_back(x);
        }
        vector<string>ans;
        for(auto &x : selected){
            ans.push_back(x.first);
        }
        return ans;
    }
};