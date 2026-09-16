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
    int mx = -1;
    void bfs(TreeNode* root) {
        if (root == NULL)
            return;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {

            vector<int> arr;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [f, v] = q.front();
                q.pop();
                arr.push_back(v);
                if(f->left) q.push({f->left,2*v+1});
                if(f->right) q.push({f->right,2*v+2});
            }
            int l = arr.size();
            if(l==1) mx = max(mx,1);
            else mx = max(mx,arr[l-1]-arr[0]+1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        bfs(root);
        return mx;
    }
};