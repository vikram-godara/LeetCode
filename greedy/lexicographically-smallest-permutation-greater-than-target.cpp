class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string ans = "";
        map<char,int>mp;
        for(char c : s)mp[c]++;

        for(int i=0;i<n;i++){
            if(mp[target[i]]>0){
                ans+=target[i];
                mp[target[i]]--;
                continue;
            }


            auto it = mp.upper_bound(target[i]);
            while(it != mp.end() && it->second == 0)
                ++it;

            if(it!=mp.end()){
                ans+=it->first;
                mp[it->first]--;

                for(auto &[c,v] : mp){
                    if(v>0)ans+=string(v,c);
                }

                return ans;
            }
            while(!ans.empty()){
                char l = ans.back();
                ans.pop_back();
                mp[l]++;
                auto it2 = mp.upper_bound(l);
                while(it2 != mp.end() && it2->second == 0)
                ++it2;
                if(it2!=mp.end()){
                    ans+=it2->first;
                    mp[it2->first]--;

                    for(auto &[c,v] : mp){
                    if(v>0)ans+=string(v,c);
                   }

                   return ans;

                    
                }
            }
            return "";
        }

        while(!ans.empty()){
                char l = ans.back();
                ans.pop_back();
                mp[l]++;
                auto it = mp.upper_bound(l);
                while(it != mp.end() && it->second == 0)
                ++it;
                if(it!=mp.end()){
                    ans+=it->first;
                    mp[it->first]--;

                    for(auto &[c,v] : mp){
                    if(v>0)ans+=string(v,c);
                   }

                   return ans;

                    
                }
        }
        return "";
    }
};