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
    void dfs(TreeNode* root , vector<TreeNode*>&v) {
        if(root == nullptr) return;
        v.push_back(root);
        dfs(root->left,v);
        dfs(root->right,v);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        vector<TreeNode*>v;
        dfs(root,v);

        for(int i =0;i<v.size()-1;i++){
            v[i]->left = nullptr;
            v[i]->right = v[i+1];
        }
        v.back()->left = nullptr;
        v.back()->right = nullptr;
    }
};