class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        auto makePalindrome = [&](string left) {
            string res = left;

            if (n % 2)
                res += mid;

            reverse(left.begin(), left.end());
            res += left;

            return res;
        };

        // Count characters available for left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        // 1. Smallest possible half
        string smallest;

        for (int i = 0; i < 26; i++)
            smallest += string(halfCnt[i], 'a' + i);

        string ans = makePalindrome(smallest);

        if (ans > target)
            return ans;

        // 2. Try target's first half exactly
        vector<int> rem = halfCnt;
        string left = "";
        bool ok = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                ok = false;
                break;
            }

            rem[x]--;
            left += target[i];
        }

        if (ok) {
            string cur = makePalindrome(left);

            if (cur > target)
                return cur;
        }

        // 3. Find smallest half strictly greater than target's half
        for (int i = m - 1; i >= 0; i--) {

            rem = halfCnt;
            left = "";
            ok = true;

            // Keep prefix equal to target
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
                left += target[j];
            }

            if (!ok)
                continue;

            // Make position i just bigger
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                string curLeft = left + char('a' + c);
                rem[c]--;

                // Fill remaining characters smallest
                for (int d = 0; d < 26; d++) {
                    while (rem[d] > 0) {
                        curLeft += char('a' + d);
                        rem[d]--;
                    }
                }

                return makePalindrome(curLeft);
            }
        }

        return "";
    }
};