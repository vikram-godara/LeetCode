class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string a;
        stack<string> st;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                st.push(a);
                a = "";
            }

            else if (s[i] == ')') {
                reverse(a.begin(), a.end());
                string b = st.top();
                st.pop();
                a  = b + a;

            } else
                a += s[i];
            i++;
        }
        return a;
    }
};