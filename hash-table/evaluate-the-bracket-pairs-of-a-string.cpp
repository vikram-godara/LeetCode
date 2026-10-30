class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        unordered_map<string, string> mp;
        for (auto& q : knowledge) {
            mp[q[0]] = q[1];
        }
        string ans;
        string key;
        bool open = false;
        ;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open = true;
                continue;
            }
            if (s[i] == ')') {
                if (mp.count(key)) {
                    ans += mp[key];
                } else
                    ans += '?';
                key = "";
                open = false;
                continue;
            }
            if (!open)
                ans += s[i];
            else {
                key += s[i];
            }
        }
        return ans;
    }
};