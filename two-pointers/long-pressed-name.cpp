class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        bool ans = true;
        int i=0,j=0;
        while(j<m){
            if( i<n && name[i] == typed[j]){
                i++;
                j++;
            }
            else if(j>0 && typed[j]==typed[j-1])j++;
            else return false;
        }
      
        return i==n;
    }
};