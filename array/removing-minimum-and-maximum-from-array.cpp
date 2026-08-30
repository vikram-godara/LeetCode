class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin(),nums.end()) -nums.begin();
        int mx = max_element(nums.begin(),nums.end()) -nums.begin();
        mn+=1;mx+=1;
        int ans = 0;
        if(mn<n-mn+1){
            ans+=mn;
            n = n-mn;
            mx = mx-mn;
            if(mx<n-mx+1) ans+=mx;
            else ans+=(n-mx+1);
        }
        else{
            ans+=(n-mn+1);
            n = mn-1;
            if(mx<=n){
                ans+=min(n-mx+1,mx);
            }
        }
        return ans;

    }
};