class Solution {
public:
    string resultingString(string s) {
        int idx = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (idx > 0 && ( (s[i] == s[idx - 1] + 1) || (s[i] + 1 == s[idx - 1]) || 
                            (s[i] == 'a' && s[idx - 1] == 'z') || (s[i] == 'z' && s[idx - 1] == 'a'))) {
                idx--;
            } else {
                s[idx++] = s[i];
            }
        }
        return s.substr(0, idx);
    }
};
