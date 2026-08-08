class Solution {
public:
    string addBinary(string a, string b) {
        int l1=a.length()-1;
        int l2=b.length()-1;
        int ca=0;
        string ans="";

        while(l1>=0 || l2>=0 || ca){
            int sum=ca;
            if(l1>=0)sum+=a[l1--]-'0';
            if(l2>=0)sum+=b[l2--]-'0';
            ans.push_back((sum%2)+'0');
            ca=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};