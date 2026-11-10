class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<char>map(26,0);
        for(char c : s){
            map[c-'a']++;
        }
        string ans = "";
        vector<string>group(s.size()+1,"");
        
        for(int x =0;x<26;x++){
            if(map[x]) group[map[x]] += char('a'+x);
        }

        for(int i=1;i<=s.size();i++){
            if(group[i].size()>=ans.size()) ans = group[i];
        }

        return ans;
    }
};