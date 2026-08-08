class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (m1[c] != "" && m1[c] != w) return false;
            if (m2[w] != 0 && m2[w] != c) return false;

            m1[c] = w;
            m2[w] = c;
        }

        return true;
    }
};