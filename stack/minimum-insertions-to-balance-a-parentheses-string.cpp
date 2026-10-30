class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0, close = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    if (open == 0) {
                        cnt += 1;
                        i++;
                    } else {
                        open--;
                        i++;
                    }
                } else {
                    if (open == 0) {
                        cnt += 2;
                    } else {
                        cnt += 1;
                        open--;
                    }
                }
            }
        }
        cnt += (2 * open);
        return cnt;
    }
};