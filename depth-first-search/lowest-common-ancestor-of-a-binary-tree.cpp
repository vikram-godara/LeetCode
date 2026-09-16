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
    void parent(TreeNode* root, TreeNode* main,unordered_map<TreeNode*,TreeNode*>&mp) {
        if (root == NULL)
            return ;
        mp[root] = main;
        parent(root->left, root,mp);
        parent(root->right, root,mp);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root,nullptr,mp);
        unordered_set<TreeNode*>st;
        
        while(p!=NULL){
            st.insert(p);
            p = mp[p];
        }
        while(!st.count(q)){
            st.insert(q);
            q = mp[q];
        }
        return q;
    }
};