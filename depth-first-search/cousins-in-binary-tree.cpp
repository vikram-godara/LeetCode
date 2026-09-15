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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,root});
        unordered_map<int,int>mp;
        while(!q.empty()){
            int n = q.size();
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                auto &[f,parent]= q.front();
                q.pop();
                
                mp[f->val] = parent->val;
                if(f->left!=nullptr) q.push({f->left,f});
                if(f->right!=nullptr) q.push({f->right,f});
            }
            if(mp.find(x) != mp.end()  && mp.find(y) !=mp.end()){
                return mp[x]!=mp[y];
            }
            if(mp.find(x)!=mp.end() || mp.find(y) !=mp.end()){
                return false;
            }
        }
        return false;
    }
};