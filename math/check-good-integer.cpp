class Solution {
public:
    bool checkGoodInteger(int n) {
        string s  = to_string(n);
        int digitsum=0;
        int square=0;
        for(int i=0;i<s.size();i++){
            int a = s[i]-'0';
            digitsum+=a;
            int pow2 = a*a;
            square+=pow2;
        }
        return (square -digitsum >=50 ? true:false);
    }
};