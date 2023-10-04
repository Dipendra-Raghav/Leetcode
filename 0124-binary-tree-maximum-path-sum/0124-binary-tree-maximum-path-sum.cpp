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
    int mx=INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)return -10000;
        int a=solve(root->left);
        int b=solve(root->right);
        mx=max({mx,a+root->val,b+root->val,(a+b+root->val),root->val,a,b});
        return max((max(a,b)+root->val),root->val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};