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
    void parent(TreeNode* root, TreeNode* main,
                unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;
        mp[root] = main;
        parent(root->left, root, mp);
        parent(root->right, root, mp);
    }
    bool isAncestor(TreeNode* a, TreeNode* b,
                    unordered_map<TreeNode*, TreeNode*>& mp) {
        while (b != NULL) {
            if (a == b)
                return true;

            b = mp[b];
        }

        return false;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root, nullptr, mp);

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> arr;
        while (!q.empty()) {
            vector<TreeNode*> curr;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* f = q.front();
                q.pop();
                curr.push_back(f);
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            arr = curr;
        }
        unordered_set<TreeNode*> st;
        int l = arr.size();
        TreeNode* final = arr[0];
        while (final != NULL) {
            bool ok = true;

            for (TreeNode* node : arr) {
                if (!isAncestor(final, node, mp)) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return final;

            final = mp[final];
        }

        return NULL;
    }
};