class Solution {
public:
    int rotatedDigits(int n) {
        
        int goodInt =0;
        for(int i=1;i<=n;i++){
            bool valid = true;
            bool diff = false;
            string s = to_string(i);
            for(int j=0;j<s.size();j++){
                if(s[j]=='3' || s[j]=='4' || s[j] =='7') {
                    valid = false;
                    break;
                }
                if(s[j]=='2' || s[j]=='5' || s[j] =='6' || s[j]=='9'){
                    diff = true;
                }
            }
            if(valid && diff) goodInt++;
        }
        return goodInt;
    }
};