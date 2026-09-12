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
    int cnt =0;
    void divide(TreeNode* main , int target){
        if(main==NULL) return;
        // if(main->left==NULL && main->right == NULL) return;

        dfs(main,target);

        divide(main->left,target);
        divide(main->right,target);
    }
    void dfs(TreeNode* root , int target){
        if(root == NULL) return;
        target-=root->val;
        if(target == 0){
            cnt++;
            // return ;
        }
        // if(root->left == nullptr && root->right==nullptr){
        //     if(target!=0) return;
        // }
        dfs(root->left,target);
        dfs(root->right,target);

    }
    int pathSum(TreeNode* root, int targetSum) {
        divide(root,targetSum);
        return cnt;
    }
};