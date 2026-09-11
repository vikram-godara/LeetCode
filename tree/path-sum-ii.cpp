/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>arr;
    void dfs(TreeNode*root ,int targetSum){
        if(root == NULL) return;
        targetSum -= root->val;
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum == 0){
                ans.push_back(arr);
            }
        }
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};