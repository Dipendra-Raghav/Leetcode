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
    void solve(TreeNode* &node)
    {
        if(node==NULL) return ;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        left=node->left;
        right=node->right;
        
        {
            cout<<"hi";
             node->left=right;
            solve(node->left);
        }
       
        {
            node->right=left;
            solve(node->right);
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        
        solve(root);
        return root;

    }
};