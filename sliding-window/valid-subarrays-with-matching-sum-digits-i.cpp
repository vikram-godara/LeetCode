class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> prefix(n+1 ,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i]; 
        }
        int cnt=0;
        for(int i= 0 ;i<n ;i++){
            for(int j = i+1;j<=n  ;j++){
                long long  diff = prefix[j] - prefix[i];
                if(diff%10 !=x) continue;

                long long a = diff;
                while(a>=10){
                    a/=10;
                }
                if(a==x) cnt++;
            }
        }
        return cnt;
    }
};