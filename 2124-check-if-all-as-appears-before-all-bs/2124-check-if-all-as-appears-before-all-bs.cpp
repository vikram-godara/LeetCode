class Solution {
public:
    bool checkString(string s) {
        char a = 'a';
        for(int c : s){
            if(c == 'a' && a == 'b'){
                return false;
            }

            if(c=='b') a = 'b';
        } 
        return true;
    }

};