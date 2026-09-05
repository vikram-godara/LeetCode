class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0 || i == candidates.size()) {
            return;
        }

        // Take candidates[i]
        curr.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i);
        curr.pop_back();

        // Skip candidates[i]
        dfs(candidates, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};