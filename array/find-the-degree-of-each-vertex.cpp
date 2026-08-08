class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>ans;
        for(auto & q : matrix){
            int sum=0;
            for(int x : q){
                sum+=x;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};