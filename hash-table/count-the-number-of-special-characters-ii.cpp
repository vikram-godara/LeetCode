class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, vector<int>> mp;
        for (int x = 0; x < word.size(); x++) {
            mp[word[x]].push_back(x);
        }
        int count = 0;
        for (auto x : mp) {
            char c = x.first;
            if (c >= 'A' && c <= 'Z') {
                char cs = c + 32;
                if (mp.count(cs)) {
                    auto p = mp[c];
                    auto q = mp[cs];
                    if (mp[c][0] > mp[cs][q.size()-1])
                        count++;
                }
            }
        }
        return count;
    }
};