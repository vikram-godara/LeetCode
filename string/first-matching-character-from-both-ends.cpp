class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        int idx =-1;
        for(int i=0;i<n;i++){
            if(s[i]==s[n-i-1]){
                // idx = i;
                return i;
            }
            
        }
        return -1;
    }
};