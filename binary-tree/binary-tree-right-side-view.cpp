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
    vector<int>ans;
    void bfs(TreeNode *root){
        if(root == nullptr ){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>arr;
            for(int i = 0;i<n;i++){
                TreeNode*f = q.front();
                q.pop();
                arr.push_back(f->val);
                if(f->left!=nullptr){
                    q.push(f->left);
                }
                if(f->right!=nullptr){
                    q.push(f->right);
                }
            }
            ans.push_back(arr[arr.size()-1]);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};