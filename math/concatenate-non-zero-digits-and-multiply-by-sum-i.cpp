class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s = "";
        if(n==0)return 0;
        while(n>0){
            int a = n%10;
            if(a!=0){
                char c = a+'0';
                s=(c) + s;
                sum+=a;
            }
            n/=10;
        }
        // s.pop_back();
        long long  x = stoi(s);
        return sum*x;
    }
};