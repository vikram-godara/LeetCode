class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n  = nums.size();
        int ans =0;
        int maxrange = INT_MIN;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int mn = s[0]-'0';
            int mx = s[0]-'0';
            for(int j=1;j<s.size();j++){
                int d = s[j]-'0';
                if(d<mn){
                    mn = d;
                }
                if(d > mx) mx = d;
            }
            int range = mx-mn;
            if(range>maxrange){
                maxrange = range;
                ans = nums[i];
            }
            else if(range == maxrange) ans+=nums[i];
            
            
        }
        return ans;
    }
};