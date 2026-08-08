class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxs=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int count=0;
            bool A[256]={0};
            for(int j=i;j<n;j++){
                char c=s[j];
                if(A[c]) break;
                A[c]=true;
                count++;

            }
            
        maxs=max(maxs,count);

        }
        return maxs;
    }
    
};