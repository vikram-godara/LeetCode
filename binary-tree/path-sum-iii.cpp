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
    int cnt=0;
    void dfs(TreeNode* main ,long long sum,int target ,unordered_map<long long,int>&mp){
        if(main==NULL) return;

        sum+=(main->val);
        cnt+=mp[sum-target];

        mp[sum]++;

        dfs(main->left,sum,target,mp);
        dfs(main->right,sum,target,mp);

        mp[sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long ,int>mp;
        mp[0] =1;
        dfs(root,0,targetSum,mp);
        return cnt;
    }
};