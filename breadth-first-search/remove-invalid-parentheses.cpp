class Solution {
public:
    unordered_set<string> st;

    void solve(string &s, int i, string curr, int balance,
               int leftRemove, int rightRemove) {

        if (balance < 0)
            return;

        if (i == s.size()) {
            if (balance == 0 && leftRemove == 0 && rightRemove == 0)
                st.insert(curr);

            return;
        }

        if (s[i] == '(') {

            if (leftRemove > 0) {
                solve(s, i + 1, curr, balance,
                      leftRemove - 1, rightRemove);
            }

            solve(s, i + 1, curr + '(', balance + 1,
                  leftRemove, rightRemove);
        }

        else if (s[i] == ')') {

            if (rightRemove > 0) {
                solve(s, i + 1, curr, balance,
                      leftRemove, rightRemove - 1);
            }

            if (balance > 0) {
                solve(s, i + 1, curr + ')', balance - 1,
                      leftRemove, rightRemove);
            }
        }

        else {
            solve(s, i + 1, curr + s[i], balance,
                  leftRemove, rightRemove);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0, "", 0, leftRemove, rightRemove);

        return vector<string>(st.begin(), st.end());
    }
};