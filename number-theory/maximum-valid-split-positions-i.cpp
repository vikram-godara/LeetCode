class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i = -1;i<n;i++){

            vector<int>a;
            for(int j= 0;j<n;j++){
                if(j!=i) a.push_back(nums[j]);
            }

            int m = a.size();
            if(m<2) continue;
            vector<int>p(m),s(m);
            p[0] = a[0];
            for(int i = 1;i<m;i++){
                p[i] = __gcd(p[i-1] ,a[i]);
            }
            s[m-1] = a[m-1];
            for(int i = m-2;i>=0;i--){
                s[i] = __gcd(s[i+1],a[i]);
            }

            int cnt=0;
            for(int i=0;i<m-1;i++){
                if(p[i] == s[i+1]){
                    cnt++;
                }
            }
            ans=max(ans,cnt);
            
        }
        return ans;
    }
};