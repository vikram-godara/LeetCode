/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int node = 0;
    int bfs(TreeNode* root) {
        if (root == NULL)
            return 1;
        int l = bfs(root->left);
        int r = bfs(root->right);
        int h = max(l,r);
        node = max(node, h);
        return 1 + max(l, r);
    }
    int maxDepth(TreeNode* root) {
        bfs(root);
        return node;
    }
};