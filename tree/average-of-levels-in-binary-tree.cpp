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
    vector<double> ans;
    void bfs(TreeNode* root) {
        if (root == nullptr)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int cnt = 0;
            int  l =  q.size();
            for (int i = 0; i <l; i++) {
                TreeNode* f = q.front();
                q.pop();
                sum += (f->val);
                cnt++;
                if (f->left != nullptr) {
                    q.push(f->left);
                }
                if (f->right != nullptr) {
                    q.push(f->right);
                }
            }
            sum = (sum/cnt);
            ans.push_back(sum);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        bfs(root);
        return ans;
    }
};