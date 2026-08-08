class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=0,even=0;
        int x =n;
        int i=1,j=2;
        while(n--){
            odd+=i;
            i+=2;
        }
        while(x--){
            even+=j;
            j+=2;
        }
        return __gcd(odd,even);
    }
};