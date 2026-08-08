class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int p=sum;
        if(sum>9*num) return "";
        string res;
        for(int i=0;i<num;i++){
            int a=min(9,sum);
            res+=(char)('0'+a);
            sum-=a;
        }
        return res;
        
        
    }
};