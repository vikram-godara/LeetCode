class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t="";
        string yy = "";
        for(auto c : s){
            if(c==y){
                yy+=c;
            }
        }
        for(auto c : yy) t+=c;
        for(auto c : s) if(c!=y) t+=c;
        return t;
    }
};