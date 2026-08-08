class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        // string s = to_string(x);
        // int n = s.size();
        // int l=0,r=n-1;
        // while(l<r){
        //     if(s[r]!=s[l]){
        //         return false;
        //     }
        //     r--;l++;
        // }
        // return true;
        long  rev =0;
        int num = x;
        while (num != 0) {
            int digit=num%10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        return rev==x;
    }
};