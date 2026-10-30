class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;
        int depth = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                depth++;
            }
            else {
                depth--;

                // Found "()"
                if (s[i - 1] == '(') {
                    ans += (1 << depth);
                }
            }
        }

        return ans;
    }
};