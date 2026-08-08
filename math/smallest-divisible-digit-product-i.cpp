class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans ;
        for(int i=n;i<=100 ;i++){
            int num = i;
            int pro = 1;
            while(num>0){
                int m = num%10;
                pro = pro*m;
                num/=10;
            }
            if(pro%t ==0){
                return i;
            }
            // else continue;
        }
        return {};
    }
};