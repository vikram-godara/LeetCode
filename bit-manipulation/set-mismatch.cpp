class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>ans;
        int dup=-1;
        long long actualsum=0;
        for(int num:nums){
            if(ans.contains(num)){
                dup=num;
            }
            ans.insert(num);
            actualsum+=num;
        }
        long long exsum=(long long )n*(n+1)/2;
        int miss=exsum-(actualsum-dup);


        return {dup,miss};
    }
};