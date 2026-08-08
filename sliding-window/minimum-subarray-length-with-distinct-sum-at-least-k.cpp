class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>copy=nums;
        unordered_map<int,int> cnt;
        long long sum=0;
        int l=0;
        int ans=INT_MAX;

        for(int r=0;r<copy.size();r++){
            if(cnt[copy[r]]==0){
                sum+=copy[r];
            }
            cnt[copy[r]]++;
            while(sum>=k){
                ans=min(ans,r-l+1);
                cnt[copy[l]]--;
                if(cnt[copy[l]]==0){
                    sum-=copy[l];
                }
                l++;
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};