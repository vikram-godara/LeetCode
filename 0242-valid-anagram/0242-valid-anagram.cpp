class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(),m = t.size();
        if(m != n) return false;
        vector<int>mp(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
            mp[t[i] -'a']--;
        }
        for(int x : mp){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};