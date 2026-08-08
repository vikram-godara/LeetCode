class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int c1=0;
        for(char c : s)if(c=='1')c1++;
        int ans = c1;
        ans = min(ans,n-c1);
        if(c1>0){
            ans=min(ans,c1-1);
        }
        else if(n>0){
            ans=min(ans,1);
        }
        if(n>=2){
            int p=0;
            if(s[0]=='0')p++;
            if(s[n-1]=='0')p++;
            for(int i=1;i<n-1;i++){
                if(s[i]=='1')p++;
            }
            ans=min(ans,p);
               
        }
        // vector<int>arr0(n+1,0),arr1(n+1,0);
        // for(int i=0;i<n;i++)if(s[i]=='1')arr.push_back(i);
        // int m = arr.size();
        // int ans=n;
        // for(int i=0;i<n;i++){
        //     arr0[i+1]=arr0[i]+(s[i]!='0');
        //     arr1[i+1]=arr1[i]+(s[i]!='1');
            // for(int j=i;j<=n;j++){
                // int zero= (arr[j]-arr[i]+1)-2;
                // int zero1 = arr[i] + (n-1-arr[j]);
                // int cost = zero1+(m-2);
                //  ans=min(ans,cost);
            
            //     int f=0;
            //     for(int k=0;k<n;k++){
            //         char c;
            //         if(k<i) c='0';
            //         else if(k<j) c ='1';
            //         else c='0';

            //         if(s[k]!=c)f++;
            //     }
            //     ans=min(ans,f);
            // }
        // }
        // for(int i=0;i<=n;i++){
        //     int c1=arr0[i]+(arr1[n]-arr1[i]);
        //     int c2=arr1[i]+(arr0[n]-arr0[i]);
        // // int a1=0,a0=0;
        // for(char c : s){
        //     if(c=='1')a1++;
        //     else a0++;
        // }
        // ans = min(ans,c1);
        // ans=min(ans,c2);
        // }

        return ans;
    }
};