class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum = 0;
        int temp = n;
        int digitproduct = 1;
        while(temp>0){
            int d = temp%10;
            digitsum+=d;
            digitproduct*=d;
            temp/=10;
        }
        return (n%(digitsum + digitproduct) == 0 ? true : false);
    }
};