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
    bool divide(TreeNode *root, TreeNode* subroot) {
        if (root==nullptr) {
            return false;
        }
        if (issame(root, subroot))
            return true;
        bool l = divide(root->left, subroot);
        bool r = divide(root->right, subroot);
        return l || r;
    }
    bool issame(TreeNode *root, TreeNode *subroot) {
        if (root == nullptr && subroot == nullptr)
            return true;
        if (root == nullptr || subroot == nullptr)
            return false;
        if (root->val != subroot->val)
            return false;
        bool l = issame(root->left, subroot->left);
        bool r = issame(root->right, subroot->right);
        return l && r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return divide(root, subRoot);
    }
};