class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
           if(s[i]=='I')ans+=1;
           else if (s[i]=='V')ans+=5;
           else if (s[i]=='X')ans+=10;
           else if (s[i]=='L')ans+=50;
           else if (s[i]=='C')ans+=100;
           else if (s[i]=='D')ans+=500;
           else ans+=1000;
        }
        for(int i=0;i<n-1;i++){
            if (s[i]=='I' && s[i+1]=='V')ans-=2;
            else if (s[i]=='I' && s[i+1]=='X')ans-=2;
            else if (s[i]=='X' && s[i+1]=='L')ans-=20;
            else if (s[i]=='X' && s[i+1]=='C')ans-=20;
            else if (s[i]=='C' && s[i+1]=='D')ans-=200;
            else if (s[i]=='C' && s[i+1]=='M')ans-=200;
        }
        return ans;
    }
};