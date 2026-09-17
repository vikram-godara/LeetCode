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

    void bfs1(TreeNode* left ,TreeNode*p,unordered_map<TreeNode*,pair<TreeNode* ,int>>&mp){
        if(left ==NULL) return ;
        queue<tuple<TreeNode*,TreeNode*,int>>q;
        q.push({left,p,0});
        while(!q.empty()){
            auto [l,p,pos] = q.front();
            q.pop();
            mp[l] = {p,pos};
            if(l->left) q.push({l->left,l,0});
            if(l->right) q.push({l->right,l,1});
        }
    }
    void bfs2(TreeNode* right ,TreeNode*p,unordered_map<TreeNode*,pair<TreeNode* ,int>>&mp){
        if(right ==NULL) return ;
        queue<tuple<TreeNode*,TreeNode*,int>>q;
        q.push({right,p,1});
        while(!q.empty()){
            auto [r,p,pos] = q.front();
            q.pop();
            mp[r] = {p,pos};
            if(r->left) q.push({r->left,r,0});
            if(r->right) q.push({r->right,r,1});
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        unordered_map<TreeNode*,pair<TreeNode* ,int>> mp1;
        unordered_map<TreeNode*,pair<TreeNode* ,int>> mp2;
        if(root->left)  bfs1(root->left,root,mp1);
        if(root->right) bfs2(root->right,root,mp2);

        for(auto &[c,par]: mp1){
            TreeNode* child = c;
            TreeNode* parent = par.first;
            int pos = par.second;
            if(pos == 0){
                parent->right = child;
            }
            else if(pos ==1){
                parent->left = child;
            }
        }
        for(auto &[c,par]: mp2){
            TreeNode* child = c;
            TreeNode* parent = par.first;
            int pos = par.second;
            if(pos == 0){
                parent->right = child;
            }
            else if(pos ==1){
                parent->left = child;
            }
        }
        return root;

    }
};