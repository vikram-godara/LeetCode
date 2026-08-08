class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counts[26] = {0}; 
        for (char c : magazine) {
            counts[c - 'a']++;
        }

        // Step 2: Subtract needed characters from the note
        for (char c : ransomNote) {
            counts[c - 'a']--;
            // If count drops below zero, magazine is missing this letter
            if (counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};