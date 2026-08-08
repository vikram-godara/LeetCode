class Solution {
public:
    vector<int>findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>fre(n+1,0);
        vector<int>ans;
        ans.reserve(n);
        for(int i=0;i<n;i++){
            fre[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(fre[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};