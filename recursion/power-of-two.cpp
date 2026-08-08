class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ans=false;
        if(n>0 && (n &(n-1))==0 ){
            ans=true;
        }
        //if(n==0) ans=true;
        return ans;
        
    }
};