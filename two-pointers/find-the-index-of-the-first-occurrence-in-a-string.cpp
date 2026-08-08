class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int l = needle.size();

        for(int i=0 ;i<=n-l;i++){
            int j=0;
            while(j<l && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==l) return i;
        }
        return -1;
    }
};