class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>ans;
        for(int num:nums){
            if(ans.find(num)!=ans.end()){
                return num;
            }
            ans.insert(num);
        }
        return -1;
    }
};