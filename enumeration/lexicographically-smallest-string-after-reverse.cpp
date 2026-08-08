class Solution {
public:
    string lexSmallest(string s) {
        int n=s.length();
        string res=s;
        for(int i=0;i<=n;i++){
            string t=s;
            reverse(t.begin(),t.begin()+i);
            if(t<res) res=t;
            
        }
        for(int i=0;i<=n;i++){
            string t=s;
            reverse(t.end()-i,t.end());
            if(t<res) res=t;
            
        }
        return res;
    }
};