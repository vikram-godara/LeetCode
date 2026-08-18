class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k==1){
            int ans =-1;
            unordered_map<int,int>mp;
            for(int x : nums){
                mp[x]++;
            }
            for(auto &[k,v]: mp){
                if(v==1){
                    ans = max(ans,k);
                }
            }
            return ans;
        }
        if(k==n)return *max_element(nums.begin(),nums.end());
        int f = nums[0];
        int l = nums[n-1];
        int cf = 1, cl =1;
        for(int i =1;i<n;i++){
            if(nums[i]==f) cf++;
        }
        for(int i =0;i<n-1;i++){
            if(nums[i]==l) cl++;
        }

        if(cl ==1 && cf == 1){
            return max(f,l);
        }
        else if (cl ==1) return l;
        else if (cf ==1) return f;
        else return -1;
    }
};