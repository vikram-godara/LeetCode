class Solution {
public:
    bool isPalindrome(string p) {
        int i = 0;
        int j = p.size() - 1;
        while (i < j) {
            if (p[i] != p[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<string> ans;
        int cnt = 0;
        // int i = 0,  j = 0;
        // string p = "";
        // while (i < n && j < n) {
        //     if(p.size()<k) p+=s[j];
        //     else{
        //         if(p[0] !=p[p.size()-1]){
        //             continue;
        //         }
        //         else{
        //             if(isPlaindrome(p)){
        //                 i = j;
        //                 cnt++;
        //             }
        //         }
        //     }
        //     i++;
        //     j++;
        // }
        int i = 0;
        while (i < n) {
            int j = i;
            string p = "";
            while (j < n) {
                p+=s[j];
                if(p.size()>=k){
                    if(isPalindrome(p)){
                        i = j+1;
                        cnt++;
                        break;
                    }
                }
                j++;
            }
            if(j==n) i++;
        }
        return cnt;
    }
};