class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        map<string,int>mp;
        vector<string>ans;
        for(int i=0;i<(1<<n) ;i++){
            string s(n,'0');
            int c =0;
            bool check = true;

            for(int j=0;j<n;j++){
                if(i& (1<<j)){
                    s[j]='1';
                    c+=j;

                    if(j>0 && s[j-1]=='1'){
                        check = false;
                    }
                }
            }
            if(check && c <=k) ans.push_back(s);
        }
        return ans;
    }
};