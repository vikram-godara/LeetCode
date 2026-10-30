class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> ans;
        set<string> cur;

        cur.insert("");

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (string x : cur)
                    ans.insert(x);

                cur.clear();
                cur.insert("");
                i++;
            }
            else {
                set<string> part;

                if (s[i] == '{') {
                    i++;
                    part = parse(s, i);
                    i++;
                }
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;

                for (string a : cur) {
                    for (string b : part) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }
        }

        for (string x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};