class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        // Check palindrome possibility
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

        // Smallest possible first half
        string half;

        for (int i = 0; i < 26; i++)
            half += string(cnt[i] / 2, 'a' + i);

        // Function to build palindrome
        auto makePalindrome = [&](string left) {
            string res = left;

            if (n % 2)
                res += mid;

            reverse(left.begin(), left.end());
            res += left;

            return res;
        };

        // IMPORTANT:
        // If the smallest half itself gives answer, return it.
        string smallest = makePalindrome(half);

        if (smallest > target)
            return smallest;

        // Now find the smallest half > target's first half
        for (int i = m - 1; i >= 0; i--) {

            vector<int> rem(26);

            for (int j = 0; j < 26; j++)
                rem[j] = cnt[j] / 2;

            // Match target[0 ... i-1]
            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
            }

            if (!ok)
                continue;

            // At position i, choose smallest character
            // strictly greater than target[i]
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                string left = target.substr(0, i);
                left += char('a' + c);

                rem[c]--;

                // Fill rest with smallest characters
                for (int d = 0; d < 26; d++) {
                    while (rem[d] > 0) {
                        left += char('a' + d);
                        rem[d]--;
                    }
                }

                return makePalindrome(left);
            }
        }

        return "";
    }
};