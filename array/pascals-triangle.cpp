class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int row = numRows;
        int start = 1;
        vector<int> prev = {1};
        vector<vector<int>> ans;
        ans.push_back(prev);
        int level = 1;
        while (level < row) {
            vector<int> curr;
            curr.push_back(1);
            int n = prev.size();
            if (n > 1) {
                for (int i = 1; i < prev.size(); i++) {
                    curr.push_back(prev[i]+prev[i-1]);
                }
            }
            curr.push_back(1);
            ans.push_back(curr);
            prev = curr;
            level++;
        }
        return ans;
    }
};