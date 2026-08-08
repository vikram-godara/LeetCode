class Solution {
public:
    bool isPowerOfFour(int n) {
        bool ans=false;
        if(n>0 && (n & (n-1))==0  && (n & 0x55555555) ){
            ans=true;
        } 
        
        //if(n==0) ans=true;
        return ans;
        
    }
};
