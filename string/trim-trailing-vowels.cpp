class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();
        //reverse(s.begin(), s.end());

        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
               s.pop_back();
            }
            else {
                break;
            }
        }
        //reverse(s.begin(), s.end());
        return s;
    }
};