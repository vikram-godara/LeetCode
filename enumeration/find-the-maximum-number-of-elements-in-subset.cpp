class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long ,int>mp;
        int mx = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int subset =1;

        if(mp.count(1)){
            if(mp[1]%2){
                subset = mp[1];
            }
            else subset = mp[1]-1;
        }
        for(auto &[key,val]:mp){
            long long x = key;
            if(x==1)continue;
            int set =0;
            while(mp.count(x)&&mp[x]>=2){
                set+=2;
                if(x>1000000000LL/x) break;
                x = x*x;
            }
            if(mp.count(x)&& mp[x]==1) set++;
            else if(set>0) set--;

            subset = max(subset,set);
        }
        return subset;
    }
};