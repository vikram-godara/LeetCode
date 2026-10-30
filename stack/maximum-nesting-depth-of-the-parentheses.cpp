class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                ans = max(ans, (int)st.size());

            }
            if (s[i] == ')') {
                st.pop();
            }
        }
        return ans;
    }
};