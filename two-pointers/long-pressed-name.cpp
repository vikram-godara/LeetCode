class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        bool ans = true;
        int i=0,j=0;
        while(i<n &&j<m){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            while((name[i]!=typed[j] && i<n && j<m)) j++;
        }
        if(j==m && i!=n) ans=false;
        return ans;
    }
};