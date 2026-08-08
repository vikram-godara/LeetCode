class Solution {
public:
    int minAllOneMultiple(int k) {
        int p=k;
        int r=0;
        for(int l=1;l<=p;++l){
            r=(r*10+1)%p;
            if(r==0) return l;
        }
        
        return -1;
    }
};