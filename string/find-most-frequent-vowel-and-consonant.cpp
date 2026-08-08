class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        for (char ch : s) {
        freq[ch - 'a']++;
        }
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
        for (char v : vowels) {
        maxVowelFreq = max(maxVowelFreq, freq[v - 'a']);
        }
        for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        // If not a vowel
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch !=     
            'o'&& ch != 'u') {
            maxConsonantFreq = max(maxConsonantFreq, freq[i]);
        }
    }
        return maxVowelFreq + maxConsonantFreq;
}
            
    

    
};