class Solution {
public:
    string smallestPalindrome(string s) {
        // map<char,int>mp;
        int n = s.size();
        // for(char c : s) mp[c]++;

        // string ans = "";
        // bool found1 = false;
        // char mid;
        // for(auto &[c,v]: mp){
        //     if(v%2){
        //         found1 = true;
        //         mid = c;
        //         break;
        //     }
        // }
        // if(found1){
        //     ans = ans+mid;
        //     mp[mid]--;

        // }
        // for(auto it = mp.rbegin();it!=mp.rend();it++){
        //     while(it->second>0){
        //         ans =it->first+ ans + it->first;
        //         it->second-=2;
        //     }
        // }
        // return ans;

        int mid = n/2;
        string a = "";
        string rev;
        for(int i=0;i<mid;i++){
            a+=s[i];
        }
        sort(a.begin(),a.end());
        rev = a;
        reverse(rev.begin(),rev.end());
        string ans;
        if(n%2){
            ans = a + s[mid] +rev;
        }
        else{
            ans = a + rev;
        }
        return ans;
    }
};