class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<int>st(word.begin(),word.end());
        map<char,int>mp;
        for(auto x : st) mp[x]++;
        int count =0;
        for(auto x : mp){
            char c = x.first;
            if(c>='A' && c<='Z'){
                char cs = c + 32;
                if(mp.count(cs)) count++;
            }
        }
        return count;
    }
};