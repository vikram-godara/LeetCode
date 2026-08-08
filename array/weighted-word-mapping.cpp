class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        unordered_map<char,int>mp;
        for(int i=0;i<26;i++){
            mp['a'+i] = weights[i];
        }
        vector<char>ch(26);
        for(int i = 0;i<26;i++){
           ch[i] = 'z'-i;
        }
        for(auto x : words){
            int res=0;
            for(auto c : x){
                res+=mp[c];
            }
           res = res%26;
           ans+=ch[res];
        }
        return ans;

    }
};