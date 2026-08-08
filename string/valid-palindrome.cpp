class Solution {
public:
    bool isPalindrome(string s) {
        // for(auto &x : s){
        //     x = tolower(x);
        // }
        // string  a = s;
        // reverse(a.begin(),a.end());

        // if(a==s)return true;
        // else return false;

        //this is two pointer problem.

        int l = 0;
        int r = s.size()-1;
        while(r>l){
            while(l<r && !isalnum(s[l]))l++;
            while(l<r && !isalnum(s[r]))r--;

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;


        }
        return true;
    }
};