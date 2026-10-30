class Solution {
public:
    int minLights(vector<int>& lights) {
        int cnt0=0;
        int ans=0;
        int l=0,r=0;
        int n = lights.size();
        // while(l<n && r<n){
        //     if(lights[r]==0) {
        //         cnt0++;
        //         r++;
        //     }
        //     else {
        //         ans+=(cnt0/2);
        //         cnt0=0;
        //         l=r;
        //         r++;
        //     }
        // }
        // ans+=(cnt0/2);

        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int l= max(0,i-lights[i]);
                int r =min(n-1,i+lights[i]);
                // for(int j=l;j<=r;j++){
                //     vis[j]=1;
                // }
                vis[l]++;
                vis[r+1]--;
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            // if(!vis[i]) cnt0++;
            // else{
            //     ans+=(cnt0+2)/3;
            //     cnt0=0;
            // }
            c+=vis[i];
            if(c==0)cnt0++;
            else{
                ans+=(cnt0+2)/3;
                cnt0=0;
            }
        }
        ans+=(cnt0+2)/3;
        return ans;
    }
};