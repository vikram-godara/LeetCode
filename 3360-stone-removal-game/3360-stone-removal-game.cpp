class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int rem = 10;
        while(n>=rem){
            n = n-rem;
            rem --;
            alice = !alice;
        }
        return !alice;
    }
};