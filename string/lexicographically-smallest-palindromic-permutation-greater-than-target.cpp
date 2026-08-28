class Solution {
public:
    string lexGreaterPalindrome(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // Check if palindrome is possible
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

        // Make smallest first half
        string half;
        for (int i = 0; i < 26; i++) {
            half += string(cnt[i] / 2, 'a' + i);
        }

        int m = n / 2;

        // Try to find answer
        for (int i = m - 1; i >= 0; i--) {

            // We will keep target's prefix [0...i-1]
            vector<int> rem = cnt;

            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] < 2) {
                    ok = false;
                    break;
                }

                rem[x] -= 2;
            }

            if (!ok)
                continue;

            // Try smallest character greater than target[i]
            for (char c = target[i] + 1; c <= 'z'; c++) {

                if (rem[c - 'a'] < 2)
                    continue;

                rem[c - 'a'] -= 2;

                string ans = target.substr(0, i);
                ans += c;

                // Fill remaining first half with smallest chars
                for (char x = 'a'; x <= 'z'; x++) {
                    while (rem[x - 'a'] >= 2 && ans.size() < m) {
                        ans += x;
                        rem[x - 'a'] -= 2;
                    }
                }

                // Build palindrome
                string res = ans;

                if (n % 2)
                    res += mid;

                string rev = ans;
                reverse(rev.begin(), rev.end());
                res += rev;

                return res;
            }
        }

        // Also check if smallest half itself works
        string res = half;

        if (n % 2)
            res += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());
        res += rev;

        if (res > target)
            return res;

        return "";
    }
};