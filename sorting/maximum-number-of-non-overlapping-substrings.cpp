class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        unordered_map<char,pair<int,int>> mp;

        for(int i=0;i<n;i++){
            if(!mp.count(s[i]))
                mp[s[i]] = {i,i};
            else
                mp[s[i]].second = i;
        }

        vector<pair<int,int>> finals;

        for(auto &[c,p] : mp){

            int l = p.first;
            int r = p.second;

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

            if(ans)
                finals.push_back({l,r});
        }

        sort(finals.begin(),finals.end(),[](auto &a,auto &b){
            return a.second < b.second;
        });

        vector<string> ans;

        int last = -1;

        for(auto &[l,r] : finals){

            if(l > last){
                ans.push_back(s.substr(l,r-l+1));
                last = r;
            }
        }

        return ans;
    }
};