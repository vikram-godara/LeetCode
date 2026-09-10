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
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;
        dfs(root,cnt);
        return cnt;

    }
private:
    int dfs(TreeNode* root ,int &cnt){
        if(root==nullptr) return 0;
        int l = dfs(root->left,cnt);
        int r = dfs(root->right,cnt);
        cnt = max(cnt,l+r);
        return 1 + max(l,r);
    }
};