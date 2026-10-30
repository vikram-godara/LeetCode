class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return 1LL*s;
        // vector<long long >seq(n);
        // seq[0] =1LL*s;
        // for(int i=1;i<n;i++){
        //     if(i%2==0) seq[i] = seq[i-1]-1;
        //     else seq[i] = seq[i-1]+m;
            
        // }
        // return *max_element(seq.begin(),seq.end());

        long long ans1=1LL*s,ans2 = 1LL*s;
        int p = n/2;
        if(p){
            ans1 = 1LL * s + m + 1LL *(p-1)*(m-1);
        }
        int p1 = (n-1)/2;
        if(p1)
            ans2 = 1LL * s+ (m-1) + 1LL*(p1-1)*(m-1);
        return max(ans1,ans2);
        
    }
};