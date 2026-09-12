/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    unordered_map<TreeNode*, TreeNode*> mp;
    void parent(TreeNode* root, TreeNode* par) {
        if (root == nullptr)
            return;
        mp[root] = par;
        parent(root->left, root);
        parent(root->right, root);
    }
    void dfs(TreeNode* main, TreeNode* form, int d, int k) {
        if (main == nullptr)
            return;
        if (d == k) {
            arr.push_back(main->val);
            return;
        }
        if (main->left != form)
            dfs(main->left, main, d + 1, k);
        if (main->right != form)
            dfs(main->right, main, d + 1, k);
        if (mp[main] != form)
            dfs(mp[main], main, d + 1, k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root, nullptr);
        dfs(target, nullptr, 0, k);
        return arr;
    }
};