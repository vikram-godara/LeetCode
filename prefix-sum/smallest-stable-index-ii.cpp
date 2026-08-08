class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>p(n),s(n);
        int stable =INT_MAX;
        p[0]=nums[0];
        for(int i=1;i<n;i++){
            // int max = *max_element(arr.begin(),arr.begin()+i);
            // int min = *min_element(arr.begin()+i,arr.end());
            // int d = max-min;
            p[i] = max(p[i-1],nums[i]);
            
            
        }
        s[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=min(s[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(p[i]-s[i]<=k)return i;
        }
        return -1;
    }
};