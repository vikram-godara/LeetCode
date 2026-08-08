class Solution {
public:
    int passwordStrength(string password) {
        string x = password;
        int n = x.size();
        unordered_set<char>s(x.begin(),x.end());
        int p=0;
        for(char c : s){
            if(c >='a' && c<='z')p++;
            else if (c >='A' && c<='Z')p+=2;
            else if(c>='0'&& c<='9')p+=3;
            else p+=5;
        }
        return p;
    }
};