class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        for(int i=0;i<n-1;i++){
            leftsum[i+1] = leftsum[i] + nums[i];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }
        vector<int>ans;
        for(int i=0;i<n;i++ ){
            int diff = abs(leftsum[i]- rightsum[i]);
            ans.push_back(diff);
        }
        return ans;
    }
};