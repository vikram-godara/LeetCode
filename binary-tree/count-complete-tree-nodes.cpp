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

    //O(n) solution
    // int  dfs(TreeNode*main){
    //     if(main==nullptr) return 0;
    //     int l = dfs(main->left);
    //     int r = dfs(main->right);
    //     return 1+l+r;
    // }

    int dfs(TreeNode *root){
        if(root==nullptr) return 0;
        int l = left(root);
        int r = right(root);

        if(l==r) return (1<<l)-1;

        return 1 + dfs(root->left) + dfs(root->right);

    }
    int left(TreeNode *root){
        int cnt =0;
        while(root!=nullptr){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int right(TreeNode *root){
        int cnt =0;
        while(root!=nullptr){
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};