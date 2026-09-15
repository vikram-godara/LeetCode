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
    int xl=-1,yl=-1;
    TreeNode* xp = nullptr;
    TreeNode* yp = nullptr;
    void dfs(TreeNode* main ,TreeNode* p, int level ,int x,int y){
        if(main == nullptr) return;
        if(main->val == x){
            xl = level;
            xp = p;
        }
        if(main->val == y){
            yl = level;
            yp = p;
        }
        dfs(main->left,main,level+1,x,y);
        dfs(main->right,main,level+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,nullptr,0,x,y);
        if((xl == yl) && (xp!=yp)){
            return true;
        }
        return false;
    }
};