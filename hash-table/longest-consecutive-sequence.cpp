class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_set<int>mp;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int mx =1;
        for(auto &k : mp){
            if(!mp.count(k-1)){
                int cnt=0;
                int num = k;
                while(mp.count(num)){
                    cnt++;
                    num++;
                }
                mx = max(mx,cnt);
            }
        }
        return mx;
    }
};