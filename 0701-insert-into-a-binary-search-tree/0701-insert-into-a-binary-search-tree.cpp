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
    void solve(TreeNode* &root,int val)
    {
        if(root->left==NULL && val<root->val)
        {
            TreeNode *node = new TreeNode(val);
            
            root->left=node;
            return ;
        }
        if(root->right==NULL && val>root->val)
        {
            TreeNode *node = new TreeNode(val);
            root->right=node;
            return ;
        }
        if(val>root->val)
        {
            solve(root->right,val);
        }
        else
        {
            solve(root->left,val);
        }
        return ;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        solve(root,val);
        return root;
    }
};