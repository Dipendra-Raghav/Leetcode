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
    int mx;
    int solve(TreeNode* root)
    {
        if(root==NULL)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        mx=max(mx,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mx=0;
        solve(root);
        return mx;
        
    }
};