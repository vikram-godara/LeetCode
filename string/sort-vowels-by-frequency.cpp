class Solution {
public:
    bool isV(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    string sortVowels(string s) {
        int n = s.size();
        string act  = s;
        string vowels = "";
        unordered_map<char,int> fre,first;
        for(int i=0;i<n;i++){
            if(isV(s[i])){
                vowels+=s[i];
                fre[s[i]]++;
                if(!first.count(s[i])) first[s[i]] = i;
            }
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b){
            if(fre[a] != fre[b]) return fre[a] > fre[b];
            return first[a] < first[b];
        });

        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isV(s[i])) {
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};