class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int c1=0;
        int l =0;
        string ans ="";        
        for(int i=0;i<n;i++){
           if(s[i]=='1'){
                if(c1<k) c1++;
                if(c1==k){
                    while(s[l] =='0') l++;
                    string x = s.substr(l,i-l+1);
                    if(ans.empty() || x.size()<ans.size() || (x.size() == ans.size() && x<ans)) ans = x;
                    c1--;
                    l++;
                    while(s[l] =='0') l++;
                }

           }
        }
        return ans;
    }
};