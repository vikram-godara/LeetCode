class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for (char ch : s) {
            // The original logic had issues with character range and comparison
            // Assuming the intent was to check only lowercase English letters
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    v++; // vowel
                } else {
                    c++; // consonant
                }
            }
        }
        if (c > 0) {
            return v / c; // floor division
        } else {
            return 0;
        }
    }
};