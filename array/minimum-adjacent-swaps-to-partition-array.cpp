class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        const int MOD = 1e9+7;
        long long ans = 0;
        long long l=0,h=0,m=0;
        for(int x : nums){
            if(x<a){
                ans+=(m+h);
                l++;
            }
            else if(x<=b){
                ans+=h;
                m++;
            }
            else{
                h++;
            }
        }
        ans%=MOD;
        return (int)ans;
        
    }
};