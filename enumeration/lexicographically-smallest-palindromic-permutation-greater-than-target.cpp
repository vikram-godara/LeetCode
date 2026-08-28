class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

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

        // Build smallest first half
        string half;
        for (int i = 0; i < 26; i++)
            half += string(cnt[i] / 2, 'a' + i);

        // Every permutation of half gives one palindrome.
        do {
            string res = half;

            if (n % 2)
                res += mid;

            string rev = half;
            reverse(rev.begin(), rev.end());
            res += rev;

            if (res > target)
                return res;

        } while (next_permutation(half.begin(), half.end()));

        return "";
    }
};