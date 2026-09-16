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
    long long  mx = -1;
    void bfs(TreeNode* root) {
        if (root == NULL)
            return;
        queue<pair<TreeNode*,  long long  >> q;
        q.push({root, 0});
        while (!q.empty()) {

            int n = q.size();
            long long first = q.front().second;
            long long last = first;
            for (int i = 0; i < n; i++) {
                auto [f, v] = q.front();
                q.pop();
                v -= first;
                last = v;
                if(f->left) q.push({f->left,2*v});
                if(f->right) q.push({f->right,2*v+1});
            }
            mx = max(mx,last+1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        bfs(root);
        return mx;
    }
};