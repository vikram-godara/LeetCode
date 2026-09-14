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
    void bfs (TreeNode *root){
        if(root==nullptr) return;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>arr;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode*front = q.front();
                q.pop();
                arr.push_back(front->val);
                if(front->left!=nullptr){
                    q.push(front->left);
                }
                if(front->right!=nullptr){
                    q.push(front->right);
                }
            }
            ans.push_back(arr);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};