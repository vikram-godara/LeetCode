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
    bool ans = false;
    int sum = 0;
    bool dfs(TreeNode *root ,int targetSum){
        if(root == nullptr) return false;
        targetSum-=root->val;
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == 0;
        }
        int l = dfs(root->left,targetSum);
        int r  = dfs(root->right,targetSum);
        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
        
    }
};