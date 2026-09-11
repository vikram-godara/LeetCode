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
    void dfs(TreeNode*root ,int targetSum,vector<int>arr){
        if(root == NULL) return;
        targetSum -= root->val;
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum == 0){
                ans.push_back(arr);
            }
        }
        dfs(root->left,targetSum,arr);
        dfs(root->right,targetSum,arr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        dfs(root,targetSum,arr);
        return ans;
    }
};