class Solution {
public:
    int minDeletion(string s, int k) {
        int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) { freq[s[i] - 'a']++; }

    int distinct = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) { distinct++; }
    }

    if (distinct <= k) { return 0; }

    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq[i] > freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }

    int deletions = 0;
    int removed = 0;
    for (int i = 0; i < 26 && removed < (distinct - k); i++) {
        if (freq[i] > 0) {
            deletions += freq[i];
            removed++;
        }
    }

    return deletions;
}
};