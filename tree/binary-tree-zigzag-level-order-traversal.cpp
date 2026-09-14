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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
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
            if(cnt%2) {
                reverse(arr.begin(),arr.end());
                ans.push_back(arr);
            }
            else ans.push_back(arr);
            cnt++;
        }
        return ans;
    }
};