class Solution {
public:
    int digitFrequencyScore(int n) {
      map<int,int>mp;
        int score=0;
        string s = to_string(n);
        for(auto x : s){
            mp[x-'0']++;
        }
        for(auto x : mp){
            int pro=(x.first * x.second);
            score+= pro;
        }
        return score;
    }
};